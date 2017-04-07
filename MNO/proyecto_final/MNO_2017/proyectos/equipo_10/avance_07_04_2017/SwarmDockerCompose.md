--- title: "Docker Swarm Deploy - Aws & Windows & Ubuntu" author: "Oscar Daniel Camarena, Max Alvarez" date: "3 de abril de 2017" output: html_document ---
#Tarea 2
## De que trata?
- Crea un /dashboard/ usando =shiny= que utilice como =backend= un servicio
  =Flask=. Para conectarte utiliza el paquete de =R= ~httr~. - El /dashboard/ muestra la base de datos =iris= 
guardada en una base de datos
  =postgresql= i.e., el servicio web de =Flask= lee la base de datos, y devuelve un =json= con
  el dataset - Agrega otro contenedor que al ejecutarse obtiene un rengln al azar del /dataset/ y lo imprime en 
pantalla
  (puedes construirlo en =bash= (=httpie=) o en =python= - Desarrolla todo, obviamente, usando =docker-compose= 
con =docker-machine= en *Amazon AWS*
#Vamonos por partes...
Antes de correr y prender servidores en AWS... armemos todos nuestros dockerFiles y en swarm-docker.compose.yml 
Necesitamos tres contenedores: 1. db: Contiene un postgres con una base de datos 2. api: Contiene un servicio 
flask que consulta el postgres 3. r: Contiene un shiny server que corre una aplicacin que consulta nuestro api 
Contenido de la carpeta dpa-postgres: Dockerfile db ```{} FROM postgres MAINTAINER Oscar Daniel Camarena 
<oscar.daniel88@gmail.com>
#ENV REFRESHED_AT 2017-03-28
ADD iris.csv /tmp/iris.csv ADD 10-initdb.sql /docker-entrypoint-initdb.d/10-initdb.sql RUN echo "host all all 
0.0.0.0/0 md5" >> /var/lib/postgresql/data/pg_hba.conf EXPOSE 5432 ``` Este Dockerfile hace referencia a un 
archivo: **10-initdb.sql** el cual contiene sentencias sql que nos ayudan a crear usuarios, crear una tabla y 
cargarle el contenido de un **.csv**. Adems, si colocamos el archivo en la ruta 
*/docker-entrypoint-initdb.d/10-initdb.sql* cuando hagamos un *docker run* se ejecutar el contenido del archivo. 
10-initdb.sql ```{} CREATE USER dpauser WITH SUPERUSER PASSWORD '123456'; CREATE DATABASE irisdb; \c irisdb 
CREATE TABLE iris(sepal_lenght decimal, sepal_width decimal, petal_length decimal, petal_width decimal, species 
text); COPY iris FROM '/tmp/iris.csv' DELIMITERS ',' CSV HEADER; ``` Adicionalmente hay que colocar en esta 
carpeta el **iris.csv** Contenido de la carpeta dpa-api Dockerfile api ```{} FROM python:3.5-slim MAINTAINER 
Adolfo De Unnue <adolfo.deunanue@itam.mx> ENV REFRESHED_AT 2017-02-14
## Actualizamos
RUN \
    apt-get -qq update; apt-get upgrade -y -qq; \
    apt-get install -y --no-install-recommends -qq wget curl git locales bzip2 unzip xz-utils build-essential; \
    apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
## Arreglamos el LOCALE
RUN echo "es_MX.UTF-8 UTF-8" >> /etc/locale.gen \
    && locale-gen es_MX.utf8 \
    && /usr/sbin/update-locale LANG=es_MX.UTF-8 \
    && dpkg-reconfigure locales RUN apt-get update \
    && apt-get install -y libblas-dev liblapack-dev gfortran \
                       libpq-dev \
                       make libssl-dev zlib1g-dev \
                       libbz2-dev libreadline-dev libsqlite3-dev llvm \
                       libncurses5-dev libncursesw5-dev xz-utils libpng12-dev \
                       libfreetype6-dev libfreetype6 libxft-dev freetype* \
                       libmysqlclient-dev
## Requerimientos
ADD requirements.txt /tmp/requirements.txt RUN pip install -r /tmp/requirements.txt
## Copiamos nuestro hola mundo
ADD postgresFlask.py /tmp/postgresFlask.py EXPOSE 8080 CMD [ "python", "/tmp/postgresFlask.py" ] ``` Este 
Dockerfile hace referencia a un archivo: **postgresFlask.py* el cual se conecta a la base de datos *irisdb* y 
regresa el contenido de la tabla *iris* en un formato *json* postgresFlask.py ```{} import psycopg2 import json 
import sys from flask import jsonify, Flask import pandas as pd import os app = Flask(__name__) @app.route("/") 
def datos():
    db_con = None
    try:
        db_con=psycopg2.connect(dbname="irisdb",user="dpauser",password="123456",host="db",port="5432")
        cursor = db_con.cursor()
        cursor.execute("SELECT * FROM iris;")
        rows=cursor.fetchall()
        column_names = [desc[0] for desc in cursor.description]
        df = pd.DataFrame(rows, columns=column_names)
        return (json.dumps(json.loads(df.reset_index().to_json(orient='records')), indent=2))
    except psycopg2.DatabaseError as e:
        print('Error %s' % e)
        return(e)
    finally:
        if db_con:
            db_con.close() if __name__=="__main__":
    port = int(os.environ.get("API_PORT", 5000))
    app.run(host="0.0.0.0",port = port) ``` Por ltimo **requirements.txt** ```{} Flask psycopg2 pandas ``` 
Contenido de la carpeta dpa-r Para este conetendor usamos la imagen de rocker/shiny que en pocas palabras es un 
servidor para aplicaciones *shiny* Dockerfile r ```{} FROM rocker/shiny MAINTAINER Oscar Daniel Camarena 
<oscar.daniel88@gmail.com> ENV REFRESHED_AT 2017-02-22
## Copiamos nuestro script en r
RUN apt-get update && apt-get install -y libssl-dev/unstable RUN echo "r <- getOption('repos'); r['CRAN'] <- 
'http://cran.us.r-project.org'; options(repos = r);" > ~/.Rprofile RUN Rscript -e "install.packages('jsonlite')" 
RUN Rscript -e "install.packages('DT')" RUN Rscript -e "install.packages('httr')" RUN Rscript -e 
"install.packages('shiny')" ADD tarea2/ /srv/shiny-server/sample-apps/tarea2/ ``` Aqui hacemos referencia a un 
directorio: **tarea2** la cual contiene dos archivos: **server.R** y **ui.R** server.R ```{} require(shiny) 
require(httr) require(jsonlite) require(DT) shinyServer(function(input, output){
  
  get <- httr::GET("api:5000/")
  res <- content(get, as= "text")
  jso <- fromJSON(res)
  db = do.call("rbind", jso)
  #colnames(db) <- c("sepal_length", "sepal_width", "petal_length", "petal_width", "class")
  
  output$tbl = DT::renderDataTable(
    db, options = list(lengthChange = FALSE))
}
) ``` ui.R ```{} require(shiny) require(httr) require(jsonlite) require(DT) shiny::fluidPage(
  titlePanel("Base de datos Iris"),
  sidebarLayout(
    sidebarPanel("our inputs will go here"),
    mainPanel(("Tabla"),
              DT::dataTableOutput('tbl'))
  ) ) ``` Para construir estas imgenes de manera sencilla, armamos un docker-compose.yml y luego ejecutamos el 
comando *docker-compose build* docker-compose.yml ```{} version: "3" services:
   db:
     build:
       context: ./dpa-postgres
       dockerfile: Dockerfile
     environment:
       - POSTGRES_USER=postgres
       - POSTGRES_PASSWORD=123456
     ports:
       - "5432:5432"
           
   api:
     build:
       context: ./dpa-flask
       dockerfile: Dockerfile
     env_file: .env
     ports:
       - "8080:8080"
   
   r:
     build:
       context: ./dpa-r
       dockerfile: Dockerfile
     env_file: .env
     ports:
       - "3838:3838" ``` .env ```{}
## Variables de la API
API_PORT=5000
## Variables de PostgreSQL
POSTGRES_USER=postgres POSTGRES_PASSWORD=123456 POSTGRES_DB=postgres ``` Una vez creadas las imagenes en nuestra 
computadora, las tagueamos para poderlas subir a *DockerHub*. Para poder lograrlo el tag debe tener la siguiente 
estructura: **username/nombre:version** ```{} docker tag tarea2_api johnydickens/ambiente_api:v0.1 docker tag 
tarea2_db johnydickens/ambiente_db:v0.1 docker tag tarea2_r johnydickens/ambiente_r:v0.1 ``` Ya tagueadas 
hacemos push y esperamos... mucho.... ```{} docker push johnydickens/ambiente_api docker push 
johnydickens/ambiente_db docker push johnydickens/ambiente_r ```
#AWS
Cuando llegamos aqui, podemos proceder a levantar servidores en *AWS* :D Si estamos en *ubuntu*: ```{} export 
MACHINE_DRIVER=amazonec2 export AWS_ACCESS_KEY_ID= export AWS_SECRET_ACCESS_KEY= export 
AWS_DEFAULT_REGION=us-west-2
# export AWS_INSTANCE_TYE=m3.large
for N in $(seq 1 4); do docker-machine create dpa-aws-node$N docker-machine ssh dpa-aws-node$N sudo usermod -aG 
docker ubuntu done ``` Si nos gusta *Windows* ```{} $Env:MACHINE_DRIVER="amazonec2" $Env:AWS_ACCESS_KEY_ID="" 
$Env:AWS_SECRET_ACCESS_KEY="" $Env:AWS_DEFAULT_REGION="us-west-1" for ($i=1; $i -le 4; $i++){ docker-machine 
create dpa-node$i docker-machine ssh dpa-node$i sudo usermod -aG docker ubuntu
} 
``` Una vez creadas sacamos la ip del nodo que ser el maestro: ```{} docker-machine ip dpa-node1 ``` Nos 
conectamos va ssh y hacemos *swarm init* ```{} docker-machine ssh dpa-node1 docker swarm init --advertise-addr 
54.183.171.222 ``` Una vez hecho esto, nos salimos del nodo1 y en nuestra consola conectamos todos los nodos 
*workers* al *master* Si estamos en *ubuntu* ```{} TOKEN=$(docker swarm join-token -q manager) for N in $(seq 2 
4); do
  eval $(docker-machine env dpa-node$N)
  docker swarm join --token $TOKEN $(docker-machine ip dpa-node1):2377 done eval $(docker-machine env dpa-node1) 
``` Si estamos en *windows* ```{} for($i=2; $i -le 4; $i++){
   & "C:\Program Files\Docker\Docker\Resources\bin\docker-machine.exe" env dpa-node$i | Invoke-Expression
   docker swarm join --token 
SWMTKN-1-5yz6ohbc8q6ricgf5ijk3vcxf61h91v8jocajxbgjb1trfsi4v-bxb8379lpsbudueugb3cp2unr 54.183.171.222:2377
}
``` Nos conectamos a **nodo1** y creamos una red ```{} docker network create --driver overlay dpa ``` Generamos 
el archivo swarm-docker-compose.yml en el **nodo1** ```{} nano swarm-docker compose.yml ``` ```{} version: "3"
 
services:
 
  db:
    image: johnydickens/ambiente_db:v0.1
    env_file: .env
    ports:
      - 5432:5432
    networks:
      - dpa
 
  api:
    image: johnydickens/ambiente_api:v0.1
    env_file: .env
    ports:
      - 5000:5000
    networks:
      - dpa
    depends_on:
      - db
      
  r:
    image: johnydickens/ambiente_r:v0.1
    env_file: .env
    ports:
      - 3838:3838
    networks:
      - dpa
    depends_on:
      - api
      
networks:
  dpa:
    external: true ``` Y de paso generamos el .env tambin ```{}
## Variables de la API
API_PORT=5000
## Variables de PostgreSQL
POSTGRES_USER=postgres POSTGRES_PASSWORD=123456 POSTGRES_DB=postgres ``` Por ultimo hacemos el *swarm stack 
deploy* ```{} docker stack deploy -c swarm-docker-compose.yml dpa ``` Listo! Para borrar las mquinas: ```{} 
for($i=1; $i -le 4; $i++){docker-machine rm -f dpa-node$i}
```

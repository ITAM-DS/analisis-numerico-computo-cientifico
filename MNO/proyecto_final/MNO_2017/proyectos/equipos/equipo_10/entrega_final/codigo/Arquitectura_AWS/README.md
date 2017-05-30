---
title: "README"
author: "Oscar Camarena, Maximiliano Alvarez"
date: "26 de mayo de 2017"
output: html_document
---

#Arquitectura de MPI distribuida en AWS

El siguiente archivo contiene las instrucciones paso a paso para levantar un ambiente de MPI distribuido utilizando *AWS*

##Lo Primero...
Entremos a nuestra consola de AWS y levantemos *N* servidores. Para fines de este tutorial *N=3*, cuando estemos creando estas maquinas nombraremos a una de ellas (indistintamente) como **Master** y las dems sern **Nodo1** y **Nodo2**

Una vez hecho eso vamos a generar el contenido nuestro archivo de hosts el cual tiene las IP's publicas de cada una de nuestras maquinas dentro de un *shell* mediante el comando **echo** de la siguiente manera:

*hosts.sh*

```{engine='bash' eval=FALSE}
#!/bin/bash

echo "127.0.0.1 localhost
54.183.187.216 master
54.241.142.234 nodo1
54.219.172.190 nodo2


# The following lines are desirable for IPv6 capable hosts
::1 ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
ff02::3 ip6-allhosts">hosts

sudo mv hosts /etc/


```


Usando la misma tecnica generaremos un programa en c que haga multiplicacion de matrices en un cluster utilizando **MPI**. Para esto escribiremos del contenido del programa en C dentro de un commando echo para luego redirigirlo a un archivo llamado *mpimm.c*

*mpimm.sh*

```{engine='bash' eval=FALSE}
#!/bin/bash

echo "
#include \"mpi.h\"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MASTER 0               /* taskid of first task */
#define FROM_MASTER 1          /* setting a message type */
#define FROM_WORKER 2          /* setting a message type */
int NRA = 0;
int NRB = 0;
int NCA = 0;
int NCB = 0;
void read_file(FILE *fp, int* rowMaxIndex, int* columnMaxIndex);
double** allocate_matrix(int rowMaxIndex, int columnMaxIndex, FILE *fp);
double** allocate_matrix_res(int rowMaxIndex,int columnMaxIndex);
int main (int argc, char *argv[])
{
int numtasks,              /* number of tasks in partition */
taskid,                /* a task identifier */
numworkers,            /* number of worker tasks */
source,                /* task id of message source */
dest,                  /* task id of message destination */
mtype,                 /* message type */
rows,                  /* rows of matrix A sent to each worker */
averow, extra, offset, /* used to determine rows sent to each worker */
i, j, k, rc;           /* misc */
int rowMaxIndexA, columnMaxIndexA;
int rowMaxIndexB, columnMaxIndexB;
double **a, **b;
FILE *fpA, *fpB;
MPI_Status status;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
if (numtasks < 2 ) {
  printf(\"Need at least two MPI tasks. Quitting...\n\");
  MPI_Abort(MPI_COMM_WORLD, rc);
  exit(1);
  }

numworkers = numtasks-1;
  //Vamos a leer de los archivos
  fpA = fopen(\"filename.csv\",\"r\"); // read mode
  if(fpA == NULL){
perror(\"Error while opening the file.\n\");
exit(EXIT_FAILURE);
}
  read_file(fpA, &rowMaxIndexA, &columnMaxIndexA);
  a = allocate_matrix(rowMaxIndexA,columnMaxIndexA, fpA);
  NRA=rowMaxIndexA;
  NCA=columnMaxIndexA;
  printf(\"NRA: %d\n\", NRA);
  printf(\"NCA: %d\n\", NCA);
  
  fpB = fopen(\"filename2.csv\",\"r\"); // read mode
  if(fpB == NULL){
        perror(\"Error while opening the file.\n\");
        exit(EXIT_FAILURE);
}
  read_file(fpB, &rowMaxIndexB, &columnMaxIndexB);
  b = allocate_matrix(rowMaxIndexB,columnMaxIndexB, fpB);
  NRB=rowMaxIndexB;
  NCB=columnMaxIndexB;
  printf(\"NRB2: %d\n\", NRB);
  printf(\"NCB2: %d\n\", NCB);
  printf(\"rowMaxIndexA=%d, columnMaxIndexB= %d\", rowMaxIndexA,columnMaxIndexB);
  printf(\"creando matriz c con %d, %d\", NRA, NCB);
  double c[NRA][NCB];
  if(columnMaxIndexA!=rowMaxIndexB){
printf(\"Multiplicacion indefinida\n\");
MPI_Abort(MPI_COMM_WORLD, rc);
exit(1);
  }

/**************************** master task ************************************/
   if (taskid == MASTER)
   {
      printf(\"mpi_mm has started with %d tasks.\n\",numtasks);
      printf(\"Initializing arrays...\n\");
  /*
      for (i=0; i<NRA; i++)
         for (j=0; j<NCA; j++)
            a[i][j]= i+j;
      for (i=0; i<NCA; i++)
         for (j=0; j<NCB; j++)
            b[i][j]= i*j;
  */



      /* Send matrix data to the worker tasks */
      averow = NRA/numworkers;
      extra = NRA%numworkers;
      offset = 0;
      mtype = FROM_MASTER;
      for (dest=1; dest<=numworkers; dest++)
      {
         rows = (dest <= extra) ? averow+1 : averow;
         printf(\"Sending %d rows to task %d offset=%d\n\",rows,dest,offset);
         MPI_Send(&offset, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&rows, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
		 MPI_Send(&NCA, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
		 //MPI_Send(&NRA, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
		 MPI_Send(&NCB, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         //MPI_Send(&a[offset][0], rows*NCA, MPI_DOUBLE, dest, mtype, MPI_COMM_WORLD);
         //MPI_Send(&b, NCA*NCB, MPI_DOUBLE, dest, mtype, MPI_COMM_WORLD);
         offset = offset + rows;
      }

      /* Receive results from worker tasks */
      mtype = FROM_WORKER;
      for (i=1; i<=numworkers; i++)
      {
         source = i;
         MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&c[offset][0], rows*NCB, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
         printf(\"Received results from task %d\n\",source);
      }

      /* Print results */
  
      printf(\"******************************************************\n\");
      printf(\"Result Matrix:\n\");
      for (i=0; i<NRA; i++)
      {
         printf(\"\n\"); 
         for (j=0; j<NCB; j++) 
	printf(\"%6.5f  \", c[i][j]);
      }
      printf(\"\n******************************************************\n\");
      printf (\"Done.\n\");
  
   }


/**************************** worker task ************************************/
   if (taskid > MASTER)
   {
      mtype = FROM_MASTER;
      MPI_Recv(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
	  MPI_Recv(&NCA, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
	  MPI_Recv(&NCB, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      //MPI_Recv(a, rows*NCA, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD, &status);
      //MPI_Recv(&b, NCA*NCB, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD, &status);
      for (k=0; k<NCB; k++)
         for (i=0; i<rows; i++)
         {
	   c[i][k]= 0.0;
            for (j=0; j<NCA; j++)
               c[i][k] = c[i][k] + a[i][j] * b[j][k];
       //printf(\"c[%d][%d]: %f\n\", i,k,c[i][k]);
         }
      mtype = FROM_WORKER;
      MPI_Send(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
      MPI_Send(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
      MPI_Send(&c, rows*NCB, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD);
  
  
   }

   MPI_Finalize();
}


void read_file(FILE *fp, int * rowMaxIndex, int * columnMaxIndex){
char part[1024];
    char *token;
int idx;
*rowMaxIndex = 0;
*columnMaxIndex=0;
while(fgets(part,1024,fp) != NULL){
        token = NULL;
 while((token = strtok((token == NULL)?part:NULL,\",\")) != NULL){
            if(*rowMaxIndex == 0){ // only want to increment column count on first loop
                *columnMaxIndex=*columnMaxIndex+1;
            }
for(idx = 0;idx<strlen(token);idx++){
                if(token[idx] == '\n'){ // this assumes there will be a \n (LF) at the end of the line
                    *rowMaxIndex=*rowMaxIndex+1;
                    break;
                }
}
 }
}
}

double** allocate_matrix(int rowMaxIndex,int columnMaxIndex, FILE *fp){
    int idx;
double **mat;
int i, j;
char part[1024];
char *token;
// allocate the matrix
    mat=malloc(sizeof(double *) * rowMaxIndex);
 if (mat == NULL){
        printf(\"ERROR: out of memory\n\");
    }
for(idx = 0;idx<rowMaxIndex;idx++){
        mat[idx] = malloc(sizeof(double *) * columnMaxIndex);
if (mat[idx] == NULL){
            printf(\"ERROR: out of memory\n\");
            break;
        }
    }

rewind(fp);
i = j = 0;
    while(fgets(part,1024,fp) != NULL){
        token = NULL;
        while((token = strtok((token == NULL)?part:NULL,\",\")) != NULL){
            mat[i][j] = atof(token);
            j = (j+1)%columnMaxIndex;
        }
        i++;
    }

    fclose(fp);
return mat;
}

double** allocate_matrix_res(int rowMaxIndex,int columnMaxIndex){
    int idx;
double **mat;
int i, j;
char part[1024];
char *token;
// allocate the matrix
printf(\"alojando matriz c con %d, %d\", rowMaxIndex, columnMaxIndex);
mat=malloc(sizeof(double *) * rowMaxIndex);
 if (mat == NULL){
        printf(\"ERROR: out of memory\n\");
    }
for(idx = 0;idx<rowMaxIndex;idx++){
        mat[idx] = malloc(sizeof(double *) * columnMaxIndex);
if (mat[idx] == NULL){
            printf(\"ERROR: out of memory\n\");
            break;
        }
    }
return mat;
}

">mpimm.c



```

El siguiente paso es generar el archivo que nos ayuda a instalar *MPI* en todos nuestras maquinas. Estos archivos seran distribuidos en paralelo a todos nuestros nodos y de manera automatica para hacer nuestra arquitectura escalable de manera facil.

*installmpi.sh*

```{engine='bash' eval=FALSE}
#!/bin/bash

sudo apt-get update -y
sudo apt-get install -y build-essential
sudo apt-get install -y nano
sudo apt-get install -y man
sudo apt-get install -y openssh-server

sudo groupadd mpi_user

sudo useradd mpi_user -g mpi_user -m -s /bin/bash

wget https://www.open-mpi.org/software/ompi/v2.0/downloads/openmpi-2.0.2.tar.gz

sudo tar xf openmpi-2.0.2.tar.gz -C /opt/

cd /opt

sudo chown -hR mpi_user:mpi_user openmpi-2.0.2

mkdir -p /var/run/sshd

cd /opt/openmpi-2.0.2

sudo ./configure --prefix=/opt/openmpi-2.0.2 --enable-orterun-prefix-by-default -with-sge

sudo make all install



```

Una vez instalado *MPI* en todos los nodos debemos cambiar algunas variables de ambiente en la consola, para eso generaremos un archivo llamado *sourcefile* que nos ayudara con esta tarea:

*sourcefile*
```{engine='bash' eval=FALSE}
#!/bin/bash
echo "export PATH=\"/opt/openmpi-2.0.2/bin:\$PATH\"
export LD_LIBRARY_PATH=\"/opt/openmpi-2.0.2/lib:LD_LIBRARY_PATH\"">sourcefile2
```

Por ultimo necesitamos un archivo maestro que nos ayude a orquestar el despliegue de los archivos a cada una de las mquinas y que ejecute todas estas tareas en rden. Dicho archivo lleva el nombre de *setup_env.sh* y su contenido se presenta a continuacion.

*setup_env.sh*

```{engine='bash' eval=FALSE}

#!/bin/bash 

aws ec2 describe-instances | \
jq '.Reservations[].Instances[].PublicDnsName' | \
tr '"' ' ' > instancias

sed 's/ //g' instancias > instancias2
rm instancias
mv instancias2 instancias

parallel --nonall --slf instancias "sudo apt-get install -y parallel"

parallel --nonall --basefile installmpi.sh  --slf instancias "./installmpi.sh"

parallel --nonall --basefile sourcefile  --slf instancias "source sourcefile"

parallel --nonall --basefile hosts.sh  --slf instancias "./hosts.sh"

parallel --nonall --basefile mpimm.sh  --slf instancias "./mpimm.sh"

parallel --nonall --basefile filename.sh  --slf instancias "./filename.sh"

parallel --nonall --basefile filename2.sh  --slf instancias "./filename2.sh"



```

**NOTA: todos los archivos .sh tienen permisos de ejecucion**

**TIP: Hay que revisar las reglas de seguridad de los nodos para que tengan una regla *Inbound* que permita ver la IP publica desde cualquier otra IP**

Nos conectamos al nodo maestro mediante *ssh*


```{engine='bash' eval=FALSE}
ssh -i "ubuntu2.pem" ubuntu@ec2-54-183-187-216.us-west-1.compute.amazonaws.com

```

Luego el *tricky*... tenemos que hacer una llave ssh

```{engine='bash' eval=FALSE}
ssh-keygen
```

Damos enter enter enter enter hasta que acabe (todo con default)

Luego hacemos un copy paste de la llave

```{engine='bash' eval=FALSE}

cat /home/ubuntu/.ssh/id_rsa.pub

#copiamos con ctrl+c

```

Nos conectamos a cada uno de los nodos y hacemos lo siguiente

```{engine='bash' eval=FALSE}
ssh -i "ubuntu2.pem" ubuntu@ec2-54-241-142-234.us-west-1.compute.amazonaws.com
cd .ssh

nano authorized_keys

#pegamos la llave al final

ssh -i "ubuntu2.pem" ubuntu@ec2-54-219-172-190.us-west-1.compute.amazonaws.com

cd .ssh

nano authorized_keys

#pegamos la llave al final
```

Nos conectamos a cada uno de los nodos y una vez conectados compilamos el archvio hello.c

```{engine='bash' eval=FALSE}
source sourcefile2
mpicc mpimm.c -o mpimm.out
```

Probamos ejecutando en el nodo maestro

```{engine='bash' eval=FALSE}
mpiexec -n 3 mpimm.out
```

Ejecutamos en modo distribuido
```{engine='bash' eval=FALSE}
mpirun --prefix /opt/openmpi-2.0.2/ -n 3 -H master,nodo1,nodo2 mpimm.out
```



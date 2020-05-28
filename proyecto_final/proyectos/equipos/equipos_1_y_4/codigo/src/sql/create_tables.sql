/***********************************************************************************/
/**************************** Preparacion de las tablas ****************************/
/***********************************************************************************/



/**************************** trabajo fuerza de ventas ****************************/
drop table if exists raw.fuerza_ventas;
create table raw.fuerza_ventas (
  fza_ventas NUMERIC,
  no_cliente NUMERIC,
  lat_destino NUMERIC,
  lon_destino NUMERIC,
  id_origen NUMERIC,
  estado VARCHAR(30),
  lat_origen NUMERIC,
  lon_origen NUMERIC
);
comment on table raw.fuerza_ventas is 'Tabla raw como venia originalmente';

/**************************** trabajo mapeo de nodos y coordenadas ****************************/
drop table if exists raw.nodos_aux;
create table raw.nodos_aux (
  id_nodo VARCHAR(20),
  lat NUMERIC,
  lon NUMERIC
);
comment on table raw.nodos_aux is 'Catálogo de nodos y coordenadas con comillas en id_nodo';


/**************************** trabajo grafos ****************************/
drop table if exists trabajo.grafos;
create table trabajo.grafos (
  id_fza_ventas NUMERIC,
  id_origen NUMERIC,
  id_destino NUMERIC,
  distancia NUMERIC
);
comment on table trabajo.grafos is 'Grafos de rutas de las fuerzas de venta';

/**************************** trabajo resultados Particle swarm ****************************/
drop table if exists trabajo.resultados;
create table trabajo.resultados (
  id_fza_ventas NUMERIC,
  algoritmo VARCHAR(5),
  ruta_optima TEXT,
  distancia NUMERIC
);
comment on table trabajo.resultados is 'Resultados del algoritmo PS y SA';

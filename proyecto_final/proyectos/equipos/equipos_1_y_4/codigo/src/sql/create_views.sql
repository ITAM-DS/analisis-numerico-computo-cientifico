drop view if exists trabajo.resultados_vw;
create view trabajo.resultados_vw as
  (select res.id_fza_ventas, res.algoritmo, sub.estado, res.ruta_optima, res.distancia
  from trabajo.resultados res,
  (select fza_ventas, estado
  from raw.fuerza_ventas
  group by fza_ventas, estado) sub
  where res.id_fza_ventas = sub.fza_ventas
);
comment on view trabajo.resultados_vw is 'Resultados que incluyen estado';

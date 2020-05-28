drop table if exists trabajo.nodos;
create table trabajo.nodos as(
    select
    substring(id_nodo  from '[^.]*')::int as nodo,
    lat, lon
    from raw.nodos_aux
);
comment on table trabajo.nodos is 'Catálogo de nodos y coordenadas sin comillas en id_nodo';

drop table if exists raw.nodos_aux;

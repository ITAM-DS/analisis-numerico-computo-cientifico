#!/usr/bin/env python


from collections import defaultdict
from heapq import heappop, heappush


def dijkstra_shortest_path(edges, start, end):
    """
    Function that receives a list of distance between edges
    and calculates the shortest path
    """

    # Almacenamos la distancia entre edges como un diccionario de listas
    # Es una forma de represetnar gráfos dirigidos.
    g = defaultdict(list)
    for l, r, c in edges:
        g[l].append((c, r))

    # Definimos un objeto para almacenar la trayectoria
    trayectoria, observados = [(0, start, ())], set()

    while q:
        # De las trayectorias a evaluar regresas el menor item del heap
        # y comienzas en ese nodo.
        # heappop es una función que obtiene el menor elemento
        (cost, v1, path) = heappop(trayectoria)

        if v1 not in observados:
            # agregas el nodo actual a los observados
            observados.add(v1)
            path = (v1, path)

            # Si llegas al destino
            if v1 == end:
                return (cost, path)

            # Si aún no estás en el destino
            # Obten todos los posibles caminos desde el nodo en donde estas
            # parado.
            for c, v2 in g.get(v1, ()):
                # para cada camino separas el costo (c) y el nodo destino v2
                if v2 not in observados:
                    # si no está en los observados lo pones para evaluarlos.
                    heappush(trayectoria, (cost + c, v2, path))

    return float("inf")


if __name__ == "__main__":
    edges = [
        ("A", "B", 12),
        ("A", "D", 30),
        ("B", "C", 10),
        ("B", "D", 800),
        ("B", "E", 40),
        ("C", "E", 20),
        ("D", "E", 15),
        ("D", "F", 60),
        ("E", "F", 85),
        ("E", "G", 90),
        ("F", "G", 100)
    ]

    distance = dijkstra_shortest_path(edges, "A", "F")
    print("La distancia mínima es: " + str(distance))
    print("Para el trayecto: " + str(distance[1]))

class vertex:
    """
    A vertex in a network.
    Attributes:
        name (string): name or identifier of vertex
        source (bool): whether the vertex is a source vertex or not
        sink (bool): whether the vertex is a sink vertex or not
    """

    def __init__(self, name, source=False, sink=False):
        self.name = name
        self.source = source
        self.sink = sink

class edge:
    """
    An edge in a netwokt, going from one vertex to another
    Attributes:
        start (vertex): the edge comes out of this vertex
        end (vertex): the edge arrives at this vertex
        capacity (float): edge's maximum flow capacity
        flow (float): current flow in the edge
        returnEdge (pointer): return edge which is used in the residual graph
    """

    def __init__(self, start, end, capacity):
        self.start = start
        self.end = end
        self.capacity = capacity
        self.flow = 0
        self.returnEdge = None

class create_flow_network:
    """
    A flow network to which we want to find the maximum flow posible going
    from one vertex to another.
    Attributes:
       vertices (list): lists all of vertices in the graph
       network (dictionary): maps every vertex's name to all of the edges
                             coming out of the said vertex
    """
    def __init__(self):
        self.vertices = []
        self.network = {}

    def get_source(self):
        """
        Finds the source vertex in the list of vertices in the network.
        """
        for vertex in self.vertices:
            if vertex.source == True:
                return vertex

        return None

    def get_sink(self):
        """
        Finds the sink vertex in the list of vertices in the flow network.
        """
        for vertex in self.vertices:
            if vertex.sink == True:
                return vertex

        return None

    def get_vertex(self, name):
        """
        Takes a vertex name finds it in the lists of vertices of the
        object of class create_flow_network.
        Args:
            name (string): name or identifier of vertex
        Returns:
            vertex (vertex): object of class vertex corresponding to the
                             input vertex name.
        """
        for vertex in self.vertices:
            if name == vertex.name:
                return vertex

    def vertex_in_network(self, name):
        """
        Verifies if a certain vertex is in the list of vertices of the flow
        network.
        Args:
            name (string): name or identifier of vertex.
        Returns:
            (bool): if the vertex is in the network or not.
        """
        for vertex in self.vertices:
            if vertex.name == name:
                return True

        return False

    def get_edges(self):
        """
        Takes information from the network vertices and gets a list of all
        the edges going in and out of this vertices.
        Returns:
            allEdges (list): list of all vertices in the flow network.
        """
        allEdges = []
        for vertex in self.network:
            for edge in self.network[vertex]:
                allEdges.append(edge)

        return allEdges

    def create_vertex(self, name, source=False, sink=False):
        """
        Creates and adds a vertex to the network after it checks various
        error cases to ensure that the vertex can be added.
        Args:
            name (string): name or identifier of vertex_in_network
            source (bool): whether the vertex to add is source or not
            sink (bool): whether the vertex to add is sink or not
        Returns:
            (string): error message when error arises
        """
        if source == True and sink == True:
            return "El nodo {} no puede ser origen y destino".format(name)

        if self.vertex_in_network(name):
            return "Nodo duplicado"

        if source == True:
            if self.get_source() != None:
                return "Ya existe nodo origen"

        if sink == True:
            if self.get_sink() != None:
                return "Ya existe nodo destino"

        newVertex = vertex(name, source, sink)
        self.vertices.append(newVertex)
        self.network[newVertex.name] = []

    def create_edge(self, start, end, capacity):
        """
        Creates and adds a new edge to the flow network with capacity of 0
        by first checking the start and end vertices of said edge to
        verify that the are not the same vertex and that they are both in
        the network.
        Args:
            start (vertex): start vertex of the new edge
            end (vertex): end vertex of the new edge
            capacity (float): capcity of the new edge
        Returns:
            (string): error message when error arises
        """

        if self.vertex_in_network(start) == False:
            print("Nodo origen ya ha sido agregado. \n El cálculo de flujo máximo continúa con el primer valor asignado al nodo orígen.")

        elif self.vertex_in_network(end) == False:
            print("Nodo destino ya ha sido agregado. \n El cálculo del flujo máximo continúa con el primer valor asignado al nodo destino.")
        
        elif start == end:
            print("No se pueden tener bucles. \n El cálculo de flujo máximo continuará sin tomar en cuenta este arco.")
          
        else:
            newEdge = edge(start, end, capacity)
            returnEdge = edge(end, start, 0)
            newEdge.returnEdge = returnEdge
            returnEdge.returnEdge = newEdge
            vertex = self.get_vertex(start)
            self.network[vertex.name].append(newEdge)
            returnVertex = self.get_vertex(end)
            self.network[returnVertex.name].append(returnEdge)

    def get_path(self, start, end, path):
        """
        Recursive function that walks through the network starting at a certain
        vertex and calculates residual capacity for each edge it passes then
        uses this residual capacity to define how much flow to send along a
        given path. Then repeats this process until it reaches the end of the
        flow network.
        Args:
            start (vertex): start vertex of the new edge
            end (vertex): end vertex of the new edge
            path (list): list of vertices in a path
        Returns:
            path (list): list of vertices in a path
        """

        if start == end:
            return path

        for edge in self.network[start]:
            residualCapacity = edge.capacity - edge.flow
            if residualCapacity > 0 and not (edge, residualCapacity) in path:
                result = self.get_path(edge.end, end, path + [(edge, residualCapacity)])
                if result != None:
                    return result

    def MaxFlow(self):
        """
        Follows the path returned by get_path and gets the maximum flow in the
        network. This function implements the Ford Fulkerson method and
        calculates the flow while the path is not fully walked. It sums this
        flow to the fordward edges and substracts it from the reverse edges.
        Then, another path is calculated and we repeat the process.
        Returns:
            (string): error message when an error in the definition of the
                      network occurs.
            (float): maximum flow through the network
        """
        source = self.get_source()
        sink = self.get_sink()

        if source == None or sink == None:
            return "La red no tiene nodo origen y/o destino "

        path = self.get_path(source.name, sink.name, [])
        while path != None:
            flow = min(edge[1] for edge in path)
            for edge, res in path:
                edge.flow += flow
                edge.returnEdge.flow -= flow
            path = self.get_path(source.name, sink.name, [])
        return sum(edge.flow for edge in self.network[source.name])


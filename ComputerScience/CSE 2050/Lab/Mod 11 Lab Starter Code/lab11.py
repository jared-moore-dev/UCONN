class Graph_ES:
    def __init__(self, V = (), E = ()):
        self._V = set()
        self._E = set()
        for v in V:
            self.add_vertex(v)
        for e in E:
            self.add_edge(e)
        
    def __len__(self):
        return len(self._V)

    def add_vertex(self, v):
        self._V.add(v)

    def remove_vertex(self, v):
        self._V.remove(v)

    def add_edge(self, e):
        self._E.add(e)

    def remove_edge(self, e):
        self._E.remove(e)

    def __iter__(self):
        return iter(self._V)

    def _neighbors(self, v):
        nbrs = set()
        for e in self._E:
            if e[0] == v: nbrs.add(e[1])
        return nbrs

class Graph_AS:
    def __init__(self, V = (), E = ()):
        self._V = set()
        self._nbrs = dict()
        for v in V:
            self.add_vertex(v)
        for e in E:
            self.add_edge(e)

    def __len__(self):
        return len(self._V)
        
    def add_vertex(self, v):
        self._V.add(v)
        self._nbrs[v] = set()
    
    def remove_vertex(self, v):
        self._V.remove(v)
    
    def add_edge(self, e):
        a, b = e
        if a not in self._nbrs:
            self._nbrs[a] = {b}
        else:
            self._nbrs[a].add(b)
        
    def remove_edge(self, e):
        a, b = e
        self._nbrs[a].remove(b)
        if len(self._nbrs[a]) == 0: 
            self._nbrs.remove(a)
    
    def __iter__(self):
        return iter(self._V)
    
    def _neighbors(self, v):
        return iter(self._nbrs[v])
    

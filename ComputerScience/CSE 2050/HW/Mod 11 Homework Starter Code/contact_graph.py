class ContactGraph:
    def __init__(self, V = (), E = ()):
        self._V = set()
        self._nbrs = dict()
        for v in V:
            self.addvertex(v)
        for e in E:
            a, b = e
            self.addedge(a, b)
        
    def verticies(self):
        return iter(self._V)
    
    def edges(self):
        for u in self._V:
            for v in self.neighbrs(u):
                yield (u,v)
        
    def addvertex(self, v):
        self._V.add(v)
        self._nbrs[v] = set()
    
    def addedge(self, u, v):
        self._nbrs[u].add(v)
    
    def removeedge(self, u, v):
        self._nbrs[u].remove(v)
    
    def __contains__(self, v):
        return v in self._nbrs
    
    def neighbors(self, v):
        return iter(self._nbrs[v])
    
    def __len__(self):
        return len(self._nbrs)
    
    def __iter__(self):
        return iter(self._V)
    
    def hasedge(self, u, v):
        return v in self._nbrs[u]

    def all_contacts(self, v):
        return iter(self.dfs(v))

    def group_contacts(self, V):
        t = set()
        for v in V:
            for neighbor in self._nbrs[v]:
                t.add(neighbor)
        yield from t

    def dfs(self, v):
        tree = {}
        tovisit = [(None, v)]
        while tovisit:
            a, b = tovisit.pop()
            if b not in tree:
                tree[b] = a
                for n in self.neighbors(b):
                    tovisit.append((b, n))
        return tree

    def contacts(self, v, d):
        visitable = [(v, 0)]
        visited = set()
        while len(visitable) > 0:
            x = visitable.pop(0)
            if x[1] > d: break
            if x[0] not in visited:
                visited.add(x[0])
                yield x
                for item in self._nbrs[x[0]]:
                    visitable.append((item, x[1] + 1))
                
    
    def bfs(G, v):
        tree = {}
        tovisit = Queue()
        tovisit.enqueue((None, v))
        while tovisit:
            a, b = tovisit.dequeue()
            if b not in tree:
                tree[b] = a
                for n in G.neighbors(b):
                    tovisit.enqueue((b, n))
        return tree
    
    

class MutualContactGraph(ContactGraph):
    def addedge(self, u, v):
        ContactGraph.addedge(self, u, v)
        ContactGraph.addedge(self, v, u)
    
    def removeedge(self, u, v):
        ContactGraph.removeedge(self, u, v)
        ContactGraph.removeedge(self, v, u)

    def edges(self):
        E = {frozenset(e) for e in ContactGraph.edges(self)}
        return iter(E)
    
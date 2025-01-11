class AdjacencySet:
    def __init__(self):
        self.V = set()
        self.nbrs = dict()

    def add_vertex(self, v):
        self.V.add(v)
    def remove_vertex(self, v):
        self.V.remove(v)

    def add_edge(self, e):
        a, b = e # e = (x, y)

        if a not in self.nbrs:
            self.nbrs[a] = {b}
        else:        
            self.nbrs[a].add(b)

    def remove_edge(self, e):
        a, b = e
        self.nbrs[a].remove(b)
        
        if len(self.nbrs[a]) == 0: self.nbrs.pop(a)

    def __iter__(self):
        return iter(self.V)

    def _neighbors(self, v):
        return iter(self.nbrs[v])

class Graph(AdjacencySet):
    def dfs(self, v):
        tree = {v:None} # child:parent pairs
        return self._dfs(v, tree = tree)

    def _dfs(self, v, tree):
        for n in g._neighbors(v):
            if n not in tree:
                tree[n] = v # child:parent pair
                return self._dfs(n, tree)
        return tree

    def dfs_iter(self, v):
        tree = {}              # child:parent pairs
        to_visit = [(None, v)] # parent, child tuples

        while to_visit:
            a, b = to_visit.pop() # a, b = (parent, child)
            if b not in tree:
                tree[b] = a # child:parent pairs
                for n in self._neighbors(b):
                    if n not in tree: to_visit.append((b, n))

        return tree 

    def bfs(self, v):
        tree = {}              # child:parent pairs
        to_visit = [(None, v)] # parent, child tuples

        while to_visit:
            a, b = to_visit.pop(0) # a, b = (parent, child)
            if b not in tree:
                tree[b] = a # child:parent pairs
                for n in self._neighbors(b):
                    if n not in tree: to_visit.append((b, n))

        return tree 

if __name__ == '__main__':
    # Store the following graph:
    # 1--4--6
    # |\ | /|
    # | \|/ |
    # 2--3--5

    g = Graph()
    vs = {1, 3, 2, 4, 5, 6}
    es = {(1,2), (1,3), (1,4),
          (2,1), (2,3),
          (3,1), (3,2), (3,4), (3,5), (3,6),
          (4,1), (4,3), (4,6),
          (5,3), (5,6),
          (6,3), (6,4), (6,5)}

    for v in vs: g.add_vertex(v)
    for e in es: g.add_edge(e)

    print("dfs(4): {}".format(g.dfs(4)))
    # None-->4-->1-->2-->3-->5-->6

    print("dfs_iter(4): {}".format(g.dfs_iter(4)))
    # None-->4-->6-->5-->3-->2-->1

    print("bfs(4): {}".format(g.bfs(4)))
    # None-->4-->1-->2
    #        |\
    #        | 3-->5
    #        |
    #        6
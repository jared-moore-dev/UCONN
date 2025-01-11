# TODO: Write tests first!!!

class Deque:
    def __init__(self):
        self._L = [] # list wrapper

    def add_first(self, item):
        self._L.insert(0, item) # O(n) 

    def add_last(self, item):
        self._L.append(item)    # O(1) 

    def remove_first(self):
        return self._L.pop(0)   # O(n)

    def remove_last(self):
        return self._L.pop()    # O(1)


if __name__ == '__main__':
    d = Deque()
    n = 10

    for i in range(n): d.add_first(i)
    for i in range(n): assert d.remove_last() == i
    print("add_first/remove_last work!")

    d = Deque()
    for i in range(n): d.add_last(i)
    for i in range(n): assert d.remove_first() == i
    print("add_last/remove_first work!")

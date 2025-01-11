# TODO: Write tests first!!! Go to the if __name__ == '__main__' block.


class Stack:
    def __init__(self):
        self._L = [] # empty list to init
                     # "List wrapper" 

    # O(1)
    def push(self, item):
        self._L.append(item)
        return None # default behavior 

    # O(1)
    def pop(self):
        return self._L.pop()

    ## TODO: add the following functions
    # O(1)
    def __len__(self):
        return len(self._L)

    # O(1)
    def peek(self):
        return self._L[-1]
    
    # O(1)
    def is_empty(self):
        return len(self) == 0

if __name__ == '__main__':
    s = Stack()
    n = 10

    assert s.is_empty()
    for i in range(n):
        assert len(s) == i
        s.push(i)
        assert not s.is_empty()
        assert s.peek() == i

    assert len(s) == n

    for i in range(n):
        assert s.pop() == n - 1 - i

    print("all done!") 

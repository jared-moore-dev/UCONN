class Node:
    def __init__(self, _item, _next):
        self._item = _item
        self._next = _next

    def __str__(self):
        if self._next is not None:
            return "Node(item = {}, next.item = {})".format(self._item, self._next._item)
        return "Node(item = {}, next = None)".format(self._item)

class LinkedList:
    def __init__(self):
        self._head = None
        self._len = 0

    def add_first(self, item):
        new_node = Node(item, self._head)
        self._head = new_node
        self._len += 1

    def __len__(self):
        return self._len

    def remove_last(self):
        # Edge case: LL is empty
        if len(self) == 0:
            raise IndexError("Cannot remove from empty LL")

        # Edge case: LL has only 1 item
        if len(self) == 1:
            # [head] --> None._next
            item = self._head._item # retrieve item
            self._head = None       # cut off tail (tail is head in this case)
            self._len -= 1          # update length
            return item             # return item

        # "Typical" case: LL has 2+ items
        # find penultimate node of LL
        penult = self._head
        while penult._next._next is not None:
            penult = penult._next

        item = penult._next._item # retrieve data
        penult._next = None       # cut off tail
        self._len -= 1            # update length
        return item               # return item


    def add_last(self, item):
        # Edge case: empty LL
        if len(self) == 0: return self.add_first(item)

        # "Typical" case: 1+ nodes in LL
        # find tail
        tail = self._head
        while tail._next is not None:
            tail = tail._next

        tail._next = Node(item, None)
        self._len += 1
    
    def remove_first(self):
        # edge case: empty LL
        if len(self) == 0: raise IndexError("Cannot remove from empty LL")
        # "typical" case: 1+ nodes
        item = self._head._item
        self._head = self._head._next
        self._len -= 1
        return item

if __name__ == '__main__':
    ll = LinkedList()
    n = 10

    for i in range(n): ll.add_first(i)
    for i in range(n): assert ll.remove_last() == i
    print("add_first and remove_last work!")

    ll = LinkedList()
    for i in range(n): ll.add_last(i)
    for i in range(n): #TODO: add test for remove_first 
    print("add_last and remove_first work!!")

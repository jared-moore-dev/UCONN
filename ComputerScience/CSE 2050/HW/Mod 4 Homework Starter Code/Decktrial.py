class ListNode:
    def __init__(self, data, prev = None, next = None):
        self.data = data
        self.prev = prev
        self.next = next
        if prev is not None:
            self.prev.next = self
        if link is not None:
            self.next.prev = self

class DeckOfCards():
    def __init__(self, L = None):
        self.len = 0
        self.head = None
        self.tail = None
        if type(L) == str:
            LS = L.split()
            for i in LS:
                self.add_to_bottom(i)
        if type(L) == list:
            for i in L:
                self.add_to_bottom(i)

    def _add(self, item, before, after):
        node = ListNode(item, before, after)
        if after is self._head:
            self._head = node
        if before is self._tail:
            self._tail = node
        self._length += 1
    
    def add_to_bottom(self, item):
        
    
    def add_to_top(self, item):
        pass

    def deal_top():
        pass
    
    def deal_bottom():

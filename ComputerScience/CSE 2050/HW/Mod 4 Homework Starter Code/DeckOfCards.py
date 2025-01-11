
class ListNode:
    def __init__(self, data, prev = None, next = None):
        self.data = data
        self.prev = prev
        self.next = next
        if prev is not None:
            self.prev.next = self
        if next is not None:
            self.next.prev = self
class DLL:
    def __init__(self):
        self._head = None
        self._tail = None
        self._length = 0
    
    def __len__(self):
        return self._length
    
    def _addbetween(self, item, before, after):
        node = ListNode(item, before, after)
        if after is self._head:
            self._head = node
        if before is self._tail:
            self._tail = node
        self._length += 1
    
    def addfirst(self, item):
        self._addbetween(item, None, self._head)
    
    def addlast(self, item):
        self._addbetween(item, self._tail, None)
    
    def _remove(self, node):
        before, after = node.prev, node.next
        if node is self._head:
            self._head = after
        else:
            before.next = after
        if node is self._tail:
            self._tail = before
        else:
            after.prev = before
        self._length -= 1
        return node.data
    
    def removefirst(self):
        return self._remove(self._head)
    def removelast(self):
        return self._remove(self._tail)

class DeckOfCards:
    def __init__(self, L = None):
        self.S = set()
        self.Deck = DLL()
        if type(L) == str:
            LS = L.split()
            for i in LS:
                self.Deck.addfirst(i)
        if type(L) == list:
            for i in L:
                self.Deck.addfirst(i)
    
    def deal_top(self):
        if self.Deck.__len__() == 0:
            raise RuntimeError
        item = self.Deck.removefirst()
        self.S.add(item)
        return item
    
    def deal_bottom(self):
        if self.Deck.__len__() == 0:
            raise RuntimeError
        item = self.Deck.removelast()
        self.S.add(item)
        return item

    def is_cheating(self, card):
        return card in self.S
    

class Node:
    def __init__(self, _item, _next=None):
        self._item = _item
        self._next = _next

class LinkedList:
    def __init__(self):
        self._head = None
        self._len = 0

    def add_first(self, item):
        # note the ternary (three-parameter) if:
        #    x = a if (boolean) else b
        # equiv to
        #    if (boolean): x = a
        #    else: x = b  
        self._head = Node(item) if (len(self) == 0) else Node(item, self._head)       

        self._len += 1


    def remove_first(self):
        if len(self) == 0: raise RuntimeError("attempt to remove_first from empty LL")

        item = self._head._item         # extract item
        self._head = self._head._next   # cut off head
        self._len -= 1                  # decrease length
        return item                     # return item

    def __len__(self):
        return self._len

    def __str__(self):
        if len(self) == 0: return ''                # edge case - just return an empty string

        list_of_strings = []                        # empty list to hold strings of each item
        self._str(self._head, list_of_strings)      # call helper function _str w/ head node
        return ''.join(list_of_strings)             # join all items in list_of_strings into one string

    # leading underscore - this is private!
    # attributes within this class, like __str__, can call it, but users should not
    # this is called a "helper" function
    def _str(self, node, list_of_strings):
        # base case: tail node
        if node._next is None:
            list_of_strings.append(str(node._item)) # add this item to the list of strings
            return                                  # start bouncing back up chain of recursive calls

        # non-base case: recursively call on next node
        else:
            self._str(node._next, list_of_strings)              # recursively call on next node
        
        # we have hit the tail, and are bouncing back up.
        # add this item to "list_of_strings", then return
        list_of_strings.insert(0, str(node._item) + "-")        # pre-pend "item-" to list of strings


#make a helper function to pass in next node 
#contains calls on helper function 

    def helper(self, node, item):
        #take vals
        #compare
        #If obj == node, return true
        #else pass next node to __in__
        #if node == last node, return false
        if (node._next is None):
            return False
        if(node._item == item):
            return True
        return self.helper(node._next, item)

    def __contains__(self, item):
        return self.helper(self._head, item)
    # TODO: recursive in
    
    def add_last_help(self, item, node):
        if node._next == None:
            newnode = Node(item)
            node._next = newnode
        else:
            self.add_last_help(item, node._next)
    
    def add_last(self, item):
        if self._len == 0:
            self.add_first(item)
            self._len += 1
        else:
            self.add_last_help(item, self._head)
            self._len += 1

if __name__ == '__main__':
    # Test Node
    n = Node(1)
    assert n._item == 1
    assert n._next is None
    print("Node tests pass")

    # Test LL - add_first/len/remove_first
    LL = LinkedList()
    
    for i in range(4):
        assert len(LL) == i
        LL.add_first(i)
    
    for i in range(4):
        assert LL.remove_first() == 3-i
        assert len(LL) == 3-i

    # Test LL - str
    for i in range(4): LL.add_first(i)
    assert str(LL) == "3-2-1-0"
    print("starter LL tests pass!")

    # TODO:
    #   * test in
    #   * test add_last


# LL = LinkedList()
# n = 10
# for i in range(n): LL.add_first(i)
    
# assert not n in LL
# assert 9 in LL
# assert 1 in L

# n = 100
# LL2 = LinkedList()
# for i in range(n):  LL2.add_last(i)
# for i in range(n): assert LL2.remove_first() == i

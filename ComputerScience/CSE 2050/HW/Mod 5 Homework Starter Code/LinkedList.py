class Node:
    def __init__(self, data, link=None):
        self.data = data
        self.link = link


def print_nodes(node):
    if node is None:
        # Base case
        print()
    else:
        # Print the current node
        print('->', node.data, end=' ')
        # Make a recursive call
        print_nodes(node.link)

def count_nodes(node, count = 0):
    if node is None:
        return count
    else:
        count += 1
        return count_nodes(node.link, count)

def sum_nodes(node, sum = 0):
    if node is None:
        return sum
    else:
        sum += node.data
        return sum_nodes(node.link, sum)

def copy(node, l):
    if node is None:
        return l
    else:
        l.add_last(node.data)
        return copy(node.link, l)

class LinkedList:
    def __init__(self):
        self._head = None
        # No counter attribute -> __len__ will be implemented recursively

    def add_first(self, item):
        self._head = Node(item, self._head)

    def remove_first(self):
        if self._head is not None:
            item = self._head.data
            self._head = self._head.link
            return item
        else:
            raise RuntimeError('Cannot remove from an empty list.')
    
    def add_last_help(self, item, node):
        if node.link == None:
            newnode = Node(item)
            node.link = newnode
        else:
            self.add_last_help(item, node.link)
    def add_last(self, item):
        if  self._head == None:
            self.add_first(item)
        else:
            self.add_last_help(item, self._head)

    # For demonstration and debug purposes: Prints all the elements
    def print_all(self):
        # Calls a recursive helper function
        print_nodes(self._head)

    # Returns the length of the linked list
    def __len__(self):
        #check to make sure 0 is what you want to send
        return count_nodes(self._head)

    # Sum all the elements in the linked list
    def sum_all(self):
        return sum_nodes(self._head)

    # Create a deep copy: Create a new linked list with all its data copied
    def deep_copy(self):
        LL = LinkedList()
        return copy(self._head, LL)

    # Reverses the list in linear time, no copying of the data
    def rev(self, node):
        #addfirst through entirety of list
        if node:
            self.add_first(node.data)
            return self.rev(node.link)

    def reverse(self):
        cur = self._head
        self.rev(self._head.link)
        cur.link = None

pl = [18, 24, 13, 30, 5]
ll = LinkedList()
for item in pl:
    ll.add_first(item)
ll.reverse()
ll.print_all()
for item in pl:
    assert(ll.remove_first() == item)
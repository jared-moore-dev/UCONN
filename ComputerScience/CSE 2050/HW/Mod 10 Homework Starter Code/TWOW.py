class Person:
    def __init__(self, name, phase, cat = None):
        self.name = name
        self.phase = phase
        self.cat = cat
    def __eq__(self, other):
        return self.name == other.name
    def __lt__(self, other):
        if self.phase < other.phase:
            return True
        elif self.phase > other.phase:
            return False
        elif self.phase == other.phase:
            if self.cat == other.cat:
                return False
            elif self.phase == 1:
                if self.cat == "FR" and (other.cat == "EL" or other.cat == None):
                    return True
                elif self.cat == "EL" and other.cat == "FR":
                    return False
                elif self.cat == "EL" and other.cat == None:
                    return True
                elif self.cat == None:
                    return False
            elif self.phase == 2:
                if self.cat == "K12" and (other.cat == "Uni" or other.cat == None):
                    return True
                elif self.cat == "Uni" and other.cat == "K12":
                    return False
                elif self.cat == "Uni" and other.cat == None:
                    return True
                elif self.cat == None:
                    return False
            elif self.phase == 3:
                if self.cat == "GP" and other.cat == None:
                    return True
                else:
                    return False
    def __le__(self, other):
        return self < other or (self.cat == other.cat and self.phase == other.phase)

    def __hash__(self):
        return hash(self.name)
    def __str__(self):
        print(self.name, self.phase, self.cat)


# class Line:
#     def __init__(self, n_avail, people = None):
#         self._L = []
#         self.n_avail = n_avail
#         self.past_sales = {}
#         if not people == None:
#             for person in people.items():
#                 self.add_buyer(person)

#     def __len__(self):
#         return len(self._L)

#     def add_buyer(self, person):
#         if not isinstance(person, Person):
#             raise TypeError
#         if person in self._L:
#             raise KeyError
#         if person in past_sales:
#             raise KeyError
#         self._L.append(person)
#         self._L.sort(reverse = True)

#     def sell_book(self):
#         sold = self._L.pop()
#         self.past_sales.add(sold)
#         self.n_avail -= 1
#         return sold

#     def add_copies(self, n):
#         self.n_avail += n

class Line:
    def __init__(self, n_avail, people = None):
        self._entries = []
        self.n_avail = n_avail
        self.all_added = set()
        if not people == None:
            for person in people:
                self._entries.append(person)
                self.all_added.add(person)
            for i in range(len(self._entries)):
                self._downheap(len(self._entries) - 1 - i)

    def add_buyer(self, person):
        #checks
        if not isinstance(person, Person):
            raise TypeError
        if person in self.all_added:
            raise KeyError
        #default code
        self._entries.append(person)
        self.all_added.add(person)
        self._upheap(len(self._entries) - 1)

    def _parent(self, i):
        return (i-1)//2

    def _children(self, i):
        left = 2*i +1
        right = 2*i +2
        return range(left, min(len(self._entries), right + 1))

    def _swap(self, a, b):
        L = self._entries
        L[a], L[b] = L[b], L[a]

    def _upheap(self, i):
        L = self._entries
        parent = self._parent(i)
        if i > 0 and L[i] < L[parent]:
            self._swap(i, parent)
            self._upheap(parent)

    def findmin(self):
        return self._entries[0]

    def sell_book(self):
        #checks
        if self.n_avail == 0:
            raise ValueError
        if len(self) == 0:
            raise IndexError
        #default code
        L = self._entries
        person = L[0]
        L[0] = L[-1]
        L.pop()
        self._downheap(0)
        #subtract from n_avail add item to memo
        self.n_avail -= 1
        return person

    def _downheap(self, i):
        L = self._entries
        children = self._children(i)
        if children:
            child = min(children, key = lambda x : L[x])
            if L[child] < L[i]:
                self._swap(i, child)
                self._downheap(child)

    
    def add_copies(self, n):
        self.n_avail += n

    def __len__(self):
        return len(self._entries)
    def __str__(self):
        for person in self._entries:
            person.__str__()
    def topstr(self):
        print(self._entries[0].__str__())

if __name__ == "__main__":
    p1 = Person("Janice", 1, "EL")
    p2 = Person("Tim", 3)
    p3 = Person("Danny", 2, "Uni")
    p4 = Person("Abby", 2, "K12")
    p5 = Person("Mike", 1, "FR")
    p6 = Person("Diego", 1)
    p7 = Person("Mark", 2)
    
    mob = [p1, p2, p3, p4, p5, p6, p7]
    line = Line(7, mob)
    print("Printing")
    line.topstr()
    print("Selling")
    assert isinstance(line.sell_book(), Person)
    line.topstr()
    print("Selling")
    line.sell_book()
    line.topstr()
    print("Selling")
    line.sell_book()
    line.topstr()
    print("Selling")
    line.sell_book()
    line.topstr()
    print("Selling")
    line.sell_book()
    line.topstr()
    print("Selling")
    line.sell_book()
    line.topstr()
    print("Selling")
    line.sell_book()
    line.sell_book()
    print("Selling")


    

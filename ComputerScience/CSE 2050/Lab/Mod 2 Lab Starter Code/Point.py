class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __gt__(self, other):
        return self.dist_from_origin() > other.dist_from_origin()
    def __lt__(self, other):
        return self.dist_from_origin() < other.dist_from_origin()
    def __eq__(self, other):
        return  (self.x == other.x) and (self.y == other.y)
    def __str__(self):
        return 'Point({}, {})'.format(self.x, self.y)
    def dist_from_origin(self):
        return (self.x**2 + self.y**2)**(1/2)


from Point import *
if __name__ == '__main__':
    p1 = Point(3, 4)
    p2 = Point(3, 4)
    p3 = Point(4, 3)
    p4 = Point(0, 1)
    #init point x, y
    assert p1.x == 3
    assert p1.y == 4


    #comparators
    # <
    assert p1 > p4 #True
    assert not(p4 > p1) #False
    assert not(p1 > p3) #False
    # >
    assert p4 < p1 #True
    assert not(p1 < p4) #False
    assert not(p3 < p1) #False
    # ==
    assert p1 == p2 
    #string
    assert str(p1) == 'Point(3, 4)'
    #dist from orgin
    assert p1.dist_from_origin() == 5.0
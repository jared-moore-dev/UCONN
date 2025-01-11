from math import sin, cos, tan, asin, acos, atan, pi


class Vector:
    def __init__(self):
        raise NotImplementedError

    def __add__(self, other):
        if isinstance(self, Vector) and isinstance(other, Vector):
            if isinstance(self, RecVec):
                newx = self.get_x() + other.get_x()
                newy = self.get_y() + other.get_y()
                return RecVec(newx, newy)
            elif isinstance(self, PolVec):
                newx = self.get_x() + other.get_x()
                newy = self.get_y() + other.get_y()
                ans = (RecVec(newx, newy)).polar()
                return ans
        else:
            raise TypeError
        # if isinstance(self, RecVec) and isinstance(other, RecVec):
        #     newx = self.get_x + other.get_x
        #     newy = self.get_y + other.get_y
        #     return RecVec(newx, newy)
        # elif isinstance(self, RecVec):
        #     orect = rectangular(other)
        #     newx = self.get_x + orect.get_x
        #     newy = self.get_y + orect.get_y
        #     return RecVec(newx, newy)
        # elif isinstance(self, PolVec) and isinstance(other, PolVec):
        #     srect = rectangular(self)
        #     orect = rectangular(other)
        #     newx = srect.get_x +

    def __sub__(self, other):
        if isinstance(self, Vector) and isinstance(other, Vector):
            if isinstance(self, RecVec):
                newx = self.get_x() - other.get_x()
                newy = self.get_y() - other.get_y()
                return RecVec(newx, newy)
            elif isinstance(self, PolVec):
                newx = self.get_x() - other.get_x()
                newy = self.get_y() - other.get_y()
                ans = (RecVec(newx, newy)).polar()
                return ans
        else:
            raise TypeError

    def __eq__(self, other):
        if isinstance(self, Vector) and isinstance(other, Vector):
            x1 = round(self.get_x(), 3)
            x2 = round(other.get_x(), 3)
            y1 = round(self.get_y(), 3)
            y2 = round(other.get_y(), 3)
            return x1==x2 and y1==y2
        else:
            raise TypeError


    def rectangular(self):
        return RecVec(self.get_x(), self.get_y())

    def polar(self):
        return PolVec(self.get_mag(), self.get_ang())


class RecVec(Vector):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "RecVec(x = {}, y = {})".format(self.get_x(), self.get_y())

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

    def get_mag(self):
        return (self.x ** 2 + self.y ** 2) ** (1/2)

    def get_ang(self):
        return atan(self.y/self.x) * (180/pi)


class PolVec(Vector):
    def __init__(self, r, a):
        self.r = r
        self.a = a

    def __str__(self):
        return "PolVec(mag = {}, angle = {})".format(self.get_mag(), self.get_ang())

    def get_x(self):
        return self.r * cos(self.a * (pi/180))

    def get_y(self):
        return self.r * sin(self.a * (pi/180))

    def get_mag(self):
        return self.r

    def get_ang(self):
        return self.a
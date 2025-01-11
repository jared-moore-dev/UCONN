import unittest
from Vector import *

class TestVector(unittest.TestCase):
    # def test_init(self):
    #     v1 = Vector(3, 4)
    #     self.assertEqual(v1.x, 3)
    #     self.assertEqual(v1.y, 4)
    # def test_add(self):
    #     v1 = Vector(3, 4)
    #     v2 = Vector(5, 6)
    #     self.assertEqual(v1+v2, Vector(8,10))
    # def test_sub(self):
    #     v1 = Vector(3, 4)
    #     v2 = Vector(5, 6)
    #     self.assertEqual(v2-v1, Vector(2,2))
    
    def test_init_NIE(self):
        with self.assertRaises(NotImplementedError):
            v1 = Vector() #should raise NotImplementedError
class TestRecVec(unittest.TestCase):
    def test_add(self):
        r1 = RecVec(3, 4)
        r2 = RecVec(5, 6)
        self.assertEqual(r1+r2, RecVec(8,10))
    def test_sub(self):
        r1 = RecVec(3, 4)
        r2 = RecVec(5, 6)
        self.assertEqual(r2-r1, RecVec(2,2))
    def test_get_x(self):
        r1 = RecVec(3, 4)
        self.assertEqual(r1.get_x(), 3)
    def test_get_y(self):
        r1 = RecVec(3, 4)
        self.assertEqual(r1.get_y(), 4)
    def test_get_mag(self):
        r1 = RecVec(3, 4)
        self.assertEqual(r1.get_mag(), 5)
    def test_get_ang(self):
        r1 = RecVec(2, 2)
        self.assertEqual(r1.get_ang(), 45)
class TestPolVec(unittest.TestCase):
    def test_add(self):
        p1 = PolVec(1, 90)
        p2 = PolVec(2, 270)
        self.assertEqual(p1+p2, PolVec(1,270))
    def test_sub(self):
        p1 = PolVec(4, 45)
        p2 = PolVec(5, 225)
        self.assertEqual(p2-p1, PolVec(2,2))
    def test_get_x(self):
        p1 = PolVec(3, 0)
        self.assertEqual(p1.get_x(), 3)
    def test_get_y(self):
        p1 = PolVec(4, 90)
        self.assertEqual(p1.get_y(), 4)
    def test_get_mag(self):
        p1 = PolVec(3, 300)
        self.assertEqual(p1.get_mag(), 3)
    def test_get_ang(self):
        p1 = PolVec(4, 22)
        self.assertEqual(p1.get_ang(), 22)
unittest.main()
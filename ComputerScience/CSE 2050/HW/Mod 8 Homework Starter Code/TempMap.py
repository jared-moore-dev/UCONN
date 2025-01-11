import random
# returns a 3-tuple of (lat, long, temperature)
def generate_report():
    # Generate random coordinates
    lat =  random.randint(0, 89) + random.random()
    long = random.randint(0, 179) + random.random()

    # 50% chance of negating lat and long (N->S and E->W)
    if random.randint(0, 1) == 0: lat *= -1
    if random.randint(0, 1) == 0: long *= -1

    # Generate temperature (gaussian distribution about 25 Celcius)
    temp = random.gauss(25, 5)

    # Return 3-tuple with position and temperature
    return (lat, long, temp)

# class TempMap():
#     def __init__(self):
#         self._size = 100
#         self._buckets = [[] for i in range(self._size)]
#         self._len = 0
    
#     def __len__(self):
#         return self._len
    
#     def __contains__(self, pos):
#         p1 = pos[0]
#         p2 = pos[1]
#         round(p1, 1)
#         round(p2, 1)
#         new = (p1, p2)
#         bucket = self._bucket(new)
#         return new in bucket
    
#     def _bucket(self, key):
#         p1 = key[0]
#         p2 = key[1]
#         round(p1, 1)
#         round(p2, 1)
#         new = (p1, p2)
#         return self._buckets [hash(new) % self._size]

#     def __getitem__(self, pos):
#         v = self._bucket(pos)
#         if (v[0] and v[1]):
#             return (v[0], v[1])
#         else:
#             raise KeyError()
        
#     def _double(self):
#         oldbuckets = self._buckets
#         self._size*=2
#         self._buckets = [ListMapping() for i in range(self._size)]
#         for bucket in oldbuckets:
#             for key, value in bucket:
#                 m = self._bucket(key)
#                 m[key] = value
    
#     def _half(self):
#         oldbuckets = self._buckets
#         self._size*=.5
#         self._buckets = [ListMapping() for i in range(self._size)]
#         for bucket in oldbuckets:
#             for key, value in bucket:
#                 m = self._bucket(key)
#                 m[key] = value


#     def add_report(self, pos, temp):
#         v = self._bucket(pos)
#         if temp > v[0]:
#             v[0] = temp
#             self._len += 1
#         if temp < v[1]:
#             v[1] = temp
#             self._len += 1
    
#     def remove_pos(self, pos):
#         if not (pos in self):
#             raise KeyError()
#         else:
#             v = self._bucket(pos)
#             for i in range(0, 2):
#                 v.remove(i)
#             self._len -=1
def roundpos(pos):
        lat = round(pos[0], 1)
        lon = round(pos[1], 1)
        new = (lat, lon)
        return new

class Entry():
    def __init__(self, pos, temp, max1 = None, min1 = None):
        self.pos = pos
        self.lat = self.pos[0]
        self.long = self.pos[1]
        self.temp = temp
        self.max = max1
        self.min = min1
    def __str__(self):
        return f"Pos: {self.pos}, Max: {self.max1}, Min: {self.min1}"
class TempMap():
    def __init__(self):
        self.n_buckets = 10
        self._L = [[] for i in range(self.n_buckets)]
        self._len = 0
    
    def __len__(self):
        return self._len
    
    def chash(self, pos):
        rpos = roundpos(pos)
        return hash(rpos) % self.n_buckets

    def rehash(self):
        self.n_buckets *= 2
        new_L = [[] for i in range(self.n_buckets)]

        for bucket in self._L:
            for entry in bucket:
                new_bucket = self.chash(entry.pos)
                new_L[new_bucket].append(entry)
        
        self._L = new_L[:]
        print("done rehashing")
    
    def dehash(self):
        self.n_buckets = self.n_buckets // 2
        new_L = [[] for i in range(self.n_buckets)]

        for bucket in self._L:
            for entry in bucket:
                new_bucket = self.chash(entry.pos)
                new_L[new_bucket].append(entry)
        
        self._L = new_L[:]
        print("done dehashing")
    
    def __getitem__(self, pos):
        bucket = self.chash(pos)
        for entry in self._L[bucket]:
            if entry.pos == roundpos(pos): return (entry.min, entry.max)
        raise KeyError("pos {} not in Mapping".format(pos))

    def __contains__(self, pos):
        rpos = roundpos(pos)
        bucket = self.chash(rpos)
        for entry in self._L[bucket]:
            if entry.pos == rpos: return True
        return False

    def add_report(self, pos, temp):
        rpos = roundpos(pos)
        bucket = self.chash(rpos)
        #Case 1: Item In mapping
        for entry in self._L[bucket]:
            #if the position at entry is equivalent to rounded pos
            if entry.pos == rpos:
                #update min and max if neccissary
                if temp > entry.max:
                    entry.max = temp
                if temp < entry.min:
                    entry.min = temp
                return
        #Case 2: Item not in mapping
        self._L[bucket].append(Entry(rpos, temp, temp, temp))
        self._len += 1
        if len(self) > self.n_buckets: 
            #print("rehashing")
            self.rehash()

    def remove_pos(self, pos):
        rpos = roundpos(pos)
        if not (rpos in self):
            raise KeyError()
        else:
            bucket = self.chash(rpos)
            for entry in self._L[bucket]:
                if entry.pos == rpos:
                    #print("removing")
                    self._L[bucket].remove(entry)
                    self._len -= 1
            if len(self) < self.n_buckets // 2: 
                #print("dehashing")
                self.dehash()
            




if __name__ == '__main__':
    # generate some reports
    n = 5
    reports = [generate_report() for i in range(n)]
    xnazzy = TempMap()

    reports = [(1.11, 2, 32), (1.1, 2, 20), (1.09, 2, 45)]

    for report in reports:
        print(report[2])
        xnazzy.add_report((report[0], report[1]), report[2])
    
    for report in reports:
        assert (report[0], report[1]) in xnazzy 

    for report in reports:
        print(xnazzy._L)
        xnazzy.remove_pos((report[0], report[1]))
    
    for report in reports:
        assert (report[0], report[1]) not in xnazzy
    

    
    # print out (lat, long) and temp w/ some formatting
    # for report in reports:
    #     print(f"(lat,long): ({report[0]}, {report[1]})\ttemp: {report[2]}")

    
class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class Mapping:
    def __init__(self):
        self.n_buckets = 100
        self._L = [[] for i in range(self.n_buckets)]
        self._len = 0

    def __setitem__(self, key, value):
        bucket = self.hash(key)

        # Case 1: item in mapping
        for entry in self._L[bucket]:
            if entry.key == key:
                entry.value = value
                return
    
        # Case 2: item not in mapping
        self._L[bucket].append(Entry(key, value))
        self._len += 1
        if len(self) > self.n_buckets: self.rehash()

    def hash(self, key):
        return key % self.n_buckets

    def __getitem__(self, key):
        bucket = self.hash(key)
        for entry in self._L[bucket]:
            if entry.key == key: return entry.value
        raise KeyError("key {} not in Mapping".format(key))
        
    def rehash(self):
        self.n_buckets *= 2
        new_L = [[] for i in range(self.n_buckets)]
        
        # move all items to new list
        for bucket in self._L:
            for entry in bucket:
                new_bucket = self.hash(entry.key)
                new_L[new_bucket].append(entry)

        self._L = new_L[:]
    
    def __len__(self):
        return(self._len)

if __name__ == '__main__':
    m = Mapping()
    n = 100000
    for i in range(n):
        m[i] = str(i)

    for i in range(n):
        assert m[i] == str(i)

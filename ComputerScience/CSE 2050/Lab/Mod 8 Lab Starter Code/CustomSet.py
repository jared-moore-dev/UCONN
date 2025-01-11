class CustomSet():
    def __init__(self):
        self._size = 100
        self._buckets = [[] for i in range(self._size)]
        self._len = 0

    def __len__(self):
        return self._len

    def __contains__(self,value):
        bucket = self._bucket(value)
        return value in bucket
    
    def _bucket (self, key):
        return self._buckets [hash(key) % self._size]
    
    def add(self,value):
        v = self._bucket(value)
        if value in v:
            return
        v.append(value)
        self._len += 1
    
    def remove(self, value):
        if not (value in self):
            raise ValueError()
        else:
            v = self._bucket(value)
            v.remove(value)
            self._len -=1
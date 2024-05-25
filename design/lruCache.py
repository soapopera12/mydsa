# 146. LRU Cache
# https://leetcode.com/problems/lru-cache
 
# implementation 1

from collections import OrderedDict

class LRUCache(object):

    # using ordered dictionary

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cache = collections.OrderedDict()
        self.size = capacity
        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.cache:
            return -1
        
        v = self.cache.pop(key)
        self.cache[key] = v   # set key as the newest one
        return v

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key not in self.cache:
            if self.size > 0:
                self.size -= 1
            else:
                self.cache.popitem(last=False)
        else:
            self.cache.pop(key)

        self.cache[key] = value
    
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

# implementation 2

from collections import deque

class LRUCache(object):
    # slow approach
    # can be done using a simple queue (double ended)

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.size = capacity
        self.deque  = deque()   # storing in key value pairs
        
    def find(self, key):
        for i in range(len(self.deque)):
            n = self.deque[i]
            if n[0] == key:
                return i         
        return -1

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        index = self.find(key)
        if index == -1:
            return -1
        else:
            k, v = self.deque[index]
            del self.deque[index]
            self.deque.append((k,v))
            return v      

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        index = self.find(key)
        if index == -1:
            if len(self.deque) >= self.size:
                self.deque.popleft()
            self.deque.append((key, value))
        else:
            del self.deque[index]
            self.deque.append((key, value))  # as a tuple


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
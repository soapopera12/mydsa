# 981. Time Based Key-Value Store
# https://leetcode.com/problems/time-based-key-value-store

class TimeMap(object):

    def __init__(self):
        # multiple values for the same key at different time stamps
        self.time_based_store = collections.defaultdict(list)
        # can also try as a dict of dict
        

    def set(self, key, value, timestamp):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        self.time_based_store[key].append((timestamp,value))
        # time_stmp = self.time_based_store.get(key, {})
        # time_stmp[timestamp] = value
        # self.time_based_store[key] = time_stmp

    def get(self, key, timestamp):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        values = self.time_based_store[key]

        if not values:
            return ''
        
        left = 0
        right = len(values) - 1

        while left < right:
            mid = (left + right + 1) / 2
            time, value = values[mid]
            if time > timestamp:
                right = mid - 1
            else:
                left = mid
        
        if values[left][0] <= timestamp:
            return values[left][1]
        else:
            return ''
        
        return ''
            





# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
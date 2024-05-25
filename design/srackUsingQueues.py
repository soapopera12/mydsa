# 225. Implement Stack using Queues
# https://leetcode.com/problems/implement-stack-using-queues

# implementation ising single queue

class MyStack(object):

    def __init__(self):
        self._queue = collections.deque()

    def push(self, x):
        q = self._queue
        q.append(x)
        for _ in range(len(q) - 1):
            q.append(q.popleft())
        
    def pop(self):
        return self._queue.popleft()

    def top(self):
        return self._queue[0]
    
    def empty(self):
        return not len(self._queue)
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

# implementation using 2 queues

from collections import deque

class MyStack(object):
    # make a stack using 2 queues
    # push from back
    # pop from front

    def __init__(self):
        self.deque1 = deque()
        self.deque2 = deque()
        self.__top = None

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.deque1.append(x)
        self.__top = x
        

    def pop(self):
        """
        :rtype: int
        """
        while len(self.deque1) > 1:  # keep the last element
            self.__top = self.deque1.popleft()
            self.deque2.append(self.__top)
        result = self.deque1.popleft()
        self.deque1, self.deque2 = self.deque2, self.deque1
        # was worrying about the for loop to shift every element one by one
        return result
        
    def top(self):
        """
        :rtype: int
        """
        return self.__top
        

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.deque1) == 0

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
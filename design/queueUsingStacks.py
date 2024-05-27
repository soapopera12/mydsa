# 232. Implement Queue using Stacks
# https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue(object):

    # the idea here is to always append in the input stack whenever we are trying to push
    # and always get elements from output stack for popping
    # in order to mantain the queue we have to modify the peek function slightly
    # the peek function will create the inverse of the stack which will keep the lastly added 
    # elements to the topside of the stack in order thereby making it easier to get them
    
    def __init__(self):
        self.in_stk = []
        self.out_stk = []

    # put everthing in one stack and then append the new item and replace
    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.in_stk.append(x)
        
    # move ecerything in the new stack except the last element and then reverse
    def pop(self):
        """
        :rtype: int
        """
        self.peek()
        return self.out_stk.pop()
        
    # return the top most element of the stafck
    def peek(self):
        """
        :rtype: int
        """
        if not self.out_stk:    # to mantain in order
            while self.in_stk:  # for holding in order
                self.out_stk.append(self.in_stk.pop())
        return self.out_stk[-1]  # last element or top most element

    # return stack.size()
    def empty(self):
        """
        :rtype: bool
        """
        return not self.in_stk and not self.out_stk
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
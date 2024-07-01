# 682. Baseball Game
# https://leetcode.com/problems/baseball-game

class Solution(object):
    def calPoints(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """
        record = []
        for i in range(len(operations)):
            if operations[i] == 'C':
                record.pop()
            elif operations[i] == 'D':
                record.append(record[-1] * 2)
            elif operations[i] == '+':
                record.append(record[-1] + record[-2])
            else:
                record.append(int(operations[i]))
        return sum(record)
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        sumArray = list()
        for i in ops:
            if i=='+':
                sumArray.append(sumArray[-1]+sumArray[-2])
            elif i == 'D':
                sumArray.append(sumArray[-1]*2)
            elif i == 'C':
                sumArray.pop()
            else:
                sumArray.append(int(i));
                
        return sum(sumArray)
        
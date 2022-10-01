class Solution:
    
    
    def solveMemo(self, idx, s, dp):
        if idx == self.l:
            return 1
        
        if dp[idx] != -1:
            return dp[idx]
        
        rec1, rec2 = 0, 0
        singleDigitLetter = int(s[idx])
        
        if(singleDigitLetter != 0):
            rec1 = self.solveMemo(idx + 1, s, dp)
            
        if(idx < self.l-1):
            twoDigitLetter = int(s[idx] + s[idx + 1])
            if(twoDigitLetter < 27 and twoDigitLetter > 9):
                rec2 = self.solveMemo(idx + 2, s, dp)
                
        dp[idx] = sum([rec1, rec2])
        return dp[idx]
    
    def solveRec(self, idx, curStr, s):
        if idx == len(s):
            return 1
        
        rec1, rec2 = 0, 0
        singleDigitLetter = int(s[idx])
        
        if(singleDigitLetter != 0):
            rec1 = self.solveRec(idx + 1, singleDigitLetter, s)
        
        if(idx < self.l-1):
            twoDigitLetter = int(s[idx] + s[idx + 1])
            if(twoDigitLetter < 27 and twoDigitLetter > 9):
                rec2 = self.solveRec(idx + 2, twoDigitLetter, s)
            
        return sum([rec1, rec2])
    
    
    def numDecodings(self, s: str) -> int:
        self.l = len(s)
        dp = [-1 for i in range(self.l+1)]
        return self.solveMemo(0, s, dp)
        return self.solveRec(0, "", s)
class Solution:
    
    def letterCombinations(self, digits: str) -> List[str]:
        
        if(len(digits)==0): return []

        hMap = {'2':'abc',
                '3' : 'def',
                '4' : 'ghi',
                '5' : 'jkl',
                '6' : 'mno',
                '7' : 'pqrs',
                '8' : "tuv",
                '9' : 'wxyz'}
        output = []
        
        def solve(idx = 0, curr_str = ''):
            
            if(idx >= len(digits)):
                output.append(curr_str)
                return None
            
            for i in hMap[digits[idx]]:
                curr_str += i
                solve(idx + 1, curr_str)
                curr_str = curr_str[:-1]
                
        solve()
            
        return output
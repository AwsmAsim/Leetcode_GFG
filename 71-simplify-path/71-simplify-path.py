class Solution:
    def simplifyPath(self, path: str) -> str:
        directories = path.split('/')
        # print(directories)
        stack = []
        for i in directories:
            if i=='..':
                if len(stack) > 0:
                    stack.pop()
            elif i != '.' and len(i)>0:
                stack.append(i)
        # print(stack)
        return '/'+('/'.join(stack))
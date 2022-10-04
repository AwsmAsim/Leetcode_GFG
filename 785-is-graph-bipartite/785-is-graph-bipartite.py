from collections import deque
class Solution:
    
    def solveBfs(self, graph):
        Q = deque()
        n = len(graph)
        visited = [-1 for i in range(n+1)]
        
        
        for i in range(n):
            if visited[i] == -1:
                Q.append(i)
                visited[i] = 0

                while len(Q):
                    node = Q.popleft()

                    for nbr in graph[node]:
                        if visited[nbr] == -1:
                            visited[nbr] = 1 - visited[node]
                            Q.append(nbr)
                        elif visited[nbr] == visited[node]:
                            return False
                
        return True
        
        
        
    
    def isBipartite(self, graph: List[List[int]]) -> bool:
        return self.solveBfs(graph)
        
        
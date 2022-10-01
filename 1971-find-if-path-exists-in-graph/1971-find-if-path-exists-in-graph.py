class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = [[] for i in range(n)]
        visited = [False for i in range(n)]
        stack = []
        
        # making edge
        for edge in edges:
            s = edge[0]
            dest = edge[1]
            
            graph[s].append(dest)
            graph[dest].append(s)
            
        
        # dfs
        starting_point = source
        stack.append(starting_point)
        
        while len(stack):
            node = stack[-1]
            stack.pop()
            
            if visited[node]:
                continue
                
            visited[node] = True
            for nbr in graph[node]:
                if not visited[nbr]:
                    stack.append(nbr)
            
        # Since we have traversed from the source
        # if the destinaton is visited, the return true
        
        return visited[destination]
                
            
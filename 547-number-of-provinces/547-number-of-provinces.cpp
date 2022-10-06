class Solution:
    
    def findSet(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.findSet(self.parent[i])
        return self.parent[i]
    
    def unionn(self, i, j):
        u = self.findSet(i)
        v = self.findSet(j)
        if u == v: return None
        
        if self.rank[u] > self.rank[v]:
            self.parent[v] = u
        elif self.rank[v] > self.rank[u]:
            self.parent[u] = v
        else:
            self.parent[v] = u
            self.rank[v] += 1
            
    def makeSet(self, n: int):
        self.parent = [i for i in range(n)]
        self.rank = [0 for i in range(n)]
            
            
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        n = len(isConnected)
        
        self.makeSet(n)
        set1 = set()
        
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1:
                    self.unionn(i, j)
                    
        for i in range(n):
            set1.add(self.findSet(i))
            
        return len(set1)
            
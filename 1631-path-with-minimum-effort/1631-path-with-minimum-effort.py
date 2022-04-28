import heapq
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m = len(heights)
        n = len(heights[0])
        vis = [[False for i in range(n)] for j in range(m)]
        q = []
        heapq.heappush(q, (0,0,0))
        while len(q) > 0:
            cur = heapq.heappop(q)
            if vis[cur[1]][cur[2]]:
                continue
            if cur[1] == m-1 and cur[2] == n-1:
                return cur[0]
            vis[cur[1]][cur[2]] = True
            for _x, _y in [(-1,0),(1,0),(0,-1),(0,1)]:
                x, y = cur[1]+_x, cur[2]+_y
                if 0<=x<m and 0<=y<n and not vis[x][y]:
                    heapq.heappush(q, (max(cur[0], abs(heights[x][y]-heights[cur[1]][cur[2]])), x, y))
        return -1
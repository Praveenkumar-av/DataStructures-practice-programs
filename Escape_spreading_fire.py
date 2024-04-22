# Escape the spreading fire problem in python

import collections

class Solution :
    def minimumMinutes(grid :list[list[int]]) -> int :
        left = 0
        right = 10**9
        r = len(grid)
        c = len(grid[0])
        INF = 10**20

        fires = collections.deque()
        dist = [[INF]*c for i in range(r)]

        directions = [(0,1),(1,0),(0,-1),(-1,0)]

        for i in range(r) :
            for j in range(c) :
                if grid[i][j] == 1 :
                    dist[i][j] = 0
                    fires.append((i,j,0))

        # finding the no. of mins to spread fire
        while len(fires) > 0 :
            x, y, d = fires.popleft()

            for dx, dy in directions :
                nx, ny = x + dx, y + dy
                if 0 <= nx < r and 0 <= ny < c and grid[nx][ny] != 2 and dist[nx][ny] == INF :
                    dist[nx][ny] = d+1
                    fires.append((nx,ny,d+1))

        # for i in range(len(dist)) :
        #     for j in range(len(dist[i])) :
        #         print(dist[i][j],end=" ")
        #     print()

        # can the person reach sefely at the given time
        def safe(time) :
            p = collections.deque()
            visted = [[0]*c for i in range(r)]

            if(time >= dist[0][0]) :
                return False
            
            p.append((0,0,time))
            
            while len(p) > 0 :
                x, y, d = p.popleft()
                
                for dx, dy in directions :
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < r and 0 <= ny < c and visted[nx][ny] == 0 and grid[nx][ny] != 2 and d+1 < dist[nx][ny] :
                        visted[nx][ny] = 1
                        p.append((nx,ny,d+1))

                        if nx == r-1 and ny == c-1 :
                            return True

                    if nx == r-1 and ny == c-1 and visted[nx][ny] == 0 and grid[nx][ny] != 2 and d+1 <= dist[nx][ny] :
                        return True
            else :  
                return False
            
        while left < right :
            mid = (left + right + 1) // 2
            print(mid)

            if safe(mid) :
                left = mid
            else :
                right = mid-1
        
        if left == 0 :
            if safe(0) :
                return 0
            else :
                return -1
            
        return left
    
obj = Solution
# lst = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
lst = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
result = obj.minimumMinutes(lst)
print('Maximum minutes :',result)

# r, c = [int(x) for x in input().split()]
# lst = []
# for i in range(r) :
#     lst.append(list([int(x) for x in input().split()]))
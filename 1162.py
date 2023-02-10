from typing import List
import numpy as np

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        grid = np.array(grid)
        adj = ((0,-1),(0,1),(-1,0),(1,0))
        if 0 in grid and 1 in grid:
            steps = 1
            while 0 in grid:
                for i in range(0,len(grid)):
                    for j in range(0, len(grid[0])):
                        # if elem is water
                        if grid[i][j] == 0:
                            # check for adjacent land
                            for a in adj:
                                if i+a[0] >= 0 and i+a[0] < len(grid) and j+a[1] >= 0 and j+a[1] < len(grid[0]):
                                    # check for current level
                                    if grid[i+a[0]][j+a[1]] == steps:
                                        # replace with next level
                                        grid[i][j] = steps + 1          
                steps += 1
            return steps - 1
        return -1

s = Solution()
grid = [[1,0,0,0,0,1,0,0,0,1],[1,1,0,1,1,1,0,1,1,0],[0,1,1,0,1,0,0,1,0,0],[1,0,1,0,1,0,0,0,0,0],[0,1,0,0,0,1,1,0,1,1],[0,0,1,0,0,1,0,1,0,1],[0,0,0,1,1,1,1,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,0,0,0,1,1,1,0,0],[1,1,0,1,1,1,1,1,0,0]]
out = s.maxDistance(grid)
print(out)
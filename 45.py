from typing import List

# functional but slow

class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        return self.jumpHelper(nums, 0, 0)

    def jumpHelper(self, nums, idx, jumps):
        if idx >= len(nums) - 1:
            return jumps
        ret = 9999
        for i in range(1,nums[idx]+1):
            ret = min(ret, self.jumpHelper(nums, idx+i, jumps+1))
        return ret

s = Solution()
io = input("nums: ")
io = list(map(int, io.split(' ')))
print(s.jump(io))
from typing import List

# warning!
# undefined behavior if end of list is unreachable

class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps, pos_s, pos_e = 0, 0, 1
        while pos_e < len(nums):
            tmp = pos_e
            pos_e = max(self.add_arr(nums[pos_s:pos_e], range(pos_s, pos_e))) + 1
            pos_s = tmp
            jumps += 1
        return jumps

    def add_arr(self, arr1, arr2):
        new_arr = []
        for i in range(0, len(arr1)):
            new_arr.append(arr1[i] + arr2[i])
        return new_arr

s = Solution()
io = input("nums: ")
io = list(map(int, io.split(' ')))
print(s.jump(io))
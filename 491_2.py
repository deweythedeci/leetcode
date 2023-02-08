from typing import List
import copy

# this shit dont work

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        return self.findSubseqHelper(nums, [])
        
    def findSubseqHelper(self, nums, curr):
        subseqs = []
        if len(curr):
            i = 0
            while(i < len(nums)):
                if nums[i] < curr[-1]:
                    nums.pop(i)
                i += 1
        if not len(nums):
            return [curr]
        for i in range(len(nums)):
            curr.append(nums.pop(i))
            subseqs.append(copy.deepcopy(curr))
            subseqs.extend(self.findSubseqHelper(copy.deepcopy(nums), copy.deepcopy(curr)))
            nums.insert(i, curr.pop())
        return subseqs

s = Solution()
print("actual",s.findSubsequences([4,6,7,7]))
print("expected",[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]])
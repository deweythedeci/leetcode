from typing import List

# incomplete

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        seqs = self.subseqHelper(nums, [])
        

    def subseqHelper(self, nums, seq):
        if nums == []:
            if len(seq) < 2:
                return []
            if not self.isAscending(seq):
                return []       
            return [seq]
        else:
            return self.subseqHelper(nums[1:], seq + [nums[0]]) + self.subseqHelper(nums[1:], seq)
    
    def isAscending(self, seq):
        for i in range(1,len(seq)):
            if(seq[i-1] > seq[i]):
                return False
        return True

s = Solution()
print("actual",s.findSubsequences([4,3,7,6]))
print("expected",[[4,7],[4,6],[3,7],[3,6]])
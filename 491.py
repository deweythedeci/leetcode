from typing import List

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        seqs = []
        self.subseqHelper(nums, [], seqs)
        return self.unique(seqs)
    
    def subseqHelper(self, nums, seq, seqs):
        if nums == []:
            if len(seq) < 2:
                return
            if not self.isAscending(seq):
                return
            seqs.append(seq)
        else:
            self.subseqHelper(nums[1:], seq + [nums[0]], seqs)
            self.subseqHelper(nums[1:], seq, seqs)
    
    def isAscending(self, seq):
        for i in range(1,len(seq)):
            if(seq[i-1] > seq[i]):
                return False
        return True

    def unique(self, arr):
        new_arr = []
        for elem in arr:
            if elem not in new_arr:
                new_arr.append(elem)
        return new_arr

s = Solution()
print("actual",s.findSubsequences([4,3,7,6]))
print("expected",[[4,7],[4,6],[3,7],[3,6]])
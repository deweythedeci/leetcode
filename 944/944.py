import numpy as np

class Solution(object):
    def minDeletionSize(self, strs):
        # convert from list of strs to 2d array of chars
        charar = np.array([list(s) for s in strs])
        # sort 2d array column wise
        sort = np.sort(charar, axis=0)
        # compares the columns between the 2 arrays
        diff = np.any(charar != sort, axis=0)
        # counts num of different columns
        return np.count_nonzero(diff)

S = Solution()
strs = ["cba","daf","ghi"]
print(S.minDeletionSize(strs))
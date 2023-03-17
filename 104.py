from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        return self.maxDepthHelper(root, 1)

    def maxDepthHelper(self, root, depth):
        left_depth = 0
        right_depth = 0
        if(root.left != None):
            left_depth = self.maxDepthHelper(root.left, 1)
        if(root.right != None):
            right_depth = self.maxDepthHelper(root.right, 1)
        return depth + max(left_depth, right_depth)

def listToTree(l, idx=0):
    if idx >= len(l) or l[idx] == None:
        return None
    root = TreeNode(l[idx])
    root.left = listToTree(l, 2*idx+1)
    root.right = listToTree(l, 2*idx+2)
    return root

def strToList(s):
    s = s.split(' ')
    for i in range(len(s)):
        if s[i] == "None":
            s[i] = None
        else:
            s[i] = int(s[i])
    return s

S = Solution()
io = input("tree: ")
io = listToTree(strToList(io))
out = S.maxDepth(io)
print(out)
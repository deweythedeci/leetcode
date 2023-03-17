# functional but too slow

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(s) == 0 or len(p) == 0:
            if len(p) == 0:
                return len(s) == 0
            if p[0] == '*':
                return self.isMatch(s, p[1:])
            return False
        if s[0] == p[0] or p[0] == '?':
            return self.isMatch(s[1:], p[1:])
        if p[0] == '*':
            return self.isMatch(s[1:], p) or self.isMatch(s, p[1:])
        return False

S = Solution()
s = input("s: ")
p = input("p: ")
out = S.isMatch(s, p)
print(out)
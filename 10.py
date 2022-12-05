class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        print(s, p)
        if p == "":
            return s == ""
        if len(p) > 1:
            if p[1] == '*':
                if s == "":
                    return self.isMatch(s,p[2:])
                if s[0] == p[0] or p[0] == '.':
                    return self.isMatch(s[1:],p) or self.isMatch(s,p[2:])
                return self.isMatch(s,p[2:])
        if len(s) == 0:
            return False
        if p[0] == '.':
            return self.isMatch(s[1:],p[1:])
        if s[0] == p[0]:
            return self.isMatch(s[1:],p[1:])
        return False

s = Solution()
print(s.isMatch("ab", ".*c"))
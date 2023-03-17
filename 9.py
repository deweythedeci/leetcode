class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        i = 0
        while 2 * i < len(x) - 1:
            if x[i] != x[len(x) - i - 1]:
                return False
            i += 1
        return True

io = int(input("x: "))
out = Solution().isPalindrome(io)
print(out)
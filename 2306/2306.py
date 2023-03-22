from typing import List

# too slow

class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        head = lambda a : a[0]
        tail = lambda a : a[1:]

        count = 0
        
        for i in range(0, len(ideas)):
            for j in range(i+1, len(ideas)):
                w1 = head(ideas[i]) + tail(ideas[j])
                w2 = head(ideas[j]) + tail(ideas[i])
                if w1 not in ideas and w2 not in ideas:
                    count += 2

        return count

S = Solution()
ideas = input("ideas: ").split(' ')
out = S.distinctNames(ideas)
print(out)
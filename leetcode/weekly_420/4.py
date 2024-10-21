from typing import List

class Solution:
    def findAnswer(self, parent: List[int], s: str) -> List[bool]:

        def is_palindrome(s: str):
            left = 0
            right = len(s) - 1
            while left < right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -= 1
            return True

        edges = {}
        for i in range(1, len(parent)):
            if parent[i] not in edges:
                edges[parent[i]] = []
            edges[parent[i]].append(i)

        ans = [False for _ in range(len(parent))]

        def dfs(x: int) -> str:
            res = ""
            if x in edges:
                for dest in edges[x]:
                    res += dfs(dest)
            res += s[x]
            ans[x] = is_palindrome(res)
            return res

        dfs(0)
        return ans

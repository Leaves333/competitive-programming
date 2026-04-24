from functools import cache

@cache
def factorial(n: int):
    return n * factorial(n-1) if n else 1

def binomial(n: int, k: int):
    return factorial(n) // (factorial(k) * factorial(n - k))

def solve(n: int, v1: int, v2: int, w: int) -> str:
    votes_needed = (n // 2) + 1
    remaining_voters = n - v1 - v2
    if v2 >= v1 + remaining_voters:
        return "RECOUNT!"

    min_voters_needed = max(0, votes_needed - v1)
    num = 0
    denom = 2 ** remaining_voters
    for i in range(min_voters_needed, remaining_voters + 1):
        num += binomial(remaining_voters, i)

    if num * 100 > w * denom:
        return "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!"
    else:
        return "PATIENCE, EVERYONE!"

t = int(input())
for _ in range(t):
    n, v1, v2, w = map(int, input().split())
    print(solve(n, v1, v2, w))

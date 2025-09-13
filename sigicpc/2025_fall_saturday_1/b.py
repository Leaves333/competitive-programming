n = int(input())
d = int(input())
s = input()[2:]

num = int(s, 2) * (2**64)
denom = 2 ** len(s) * (2**64)

a = 0
b = denom

ans = ""
for _ in range(n):
    mid = a + (d * (b - a)) // 8
    if num >= mid:
        ans += "B"
        a = mid
    else:
        ans += "A"
        b = mid

print(ans)

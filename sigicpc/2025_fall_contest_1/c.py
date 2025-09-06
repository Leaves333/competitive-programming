for _ in range(int(input())):
    seen = set()
    n = int(input())
    nums = list(map(int, input().split()))

    res = 0
    seen.add(nums[0])
    if nums[0] == 0:
        res += 1

    total = nums[0]
    for i in range(1, n):
        total += nums[i]
        seen.add(nums[i])
        if total % 2 == 0 and (total // 2) in seen:
            res += 1

    print(res)

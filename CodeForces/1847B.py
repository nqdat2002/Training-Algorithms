for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    cur = arr[0]
    part = 1
    for i in range(0, n):
        cur &= arr[i]
        if cur == 0:
            if i == n - 1: break
            part += 1
            cur = arr[i + 1]
    if cur != 0: part -= 1
    part = max(part, 1)
    print(part)

def min_divisor(n):
    for d in range(2, int(n ** 0.5) + 1):
        if n % d == 0:
            return d
    return n

for _ in range(int(input())):
    l, r = map(int, input().split())
    ok = False
    for x in range(l, r + 1):
        y = min_divisor(x)
        if y != x:
            print(y, x - y)
            ok = True
            break
    if not ok: 
        print(-1)
n = int(input())
a = list(map(int, input().split()))

ans = 0
l = 0
while l < n:
    r = l + 1
    hasTwo = (a[l] == 2)
    ok = False
    while r < n:
        if r - 1 > l and a[r - 1] == 0:
            ok = True
        if a[r] == 2:
            hasTwo = True
        good = (not ok) and (hasTwo or a[l] != 0 or a[r] != 0)
        if not good:
            break
        r += 1
    l = r
    ans += 1
    
print(ans)
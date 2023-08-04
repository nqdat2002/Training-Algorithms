def solve():
    n, m = map(int, input().split())
    segs = []
    for i in range(m):
        l, r = map(int, input().split())
        l -= 1
        segs.append([l, r])
    q = int(input())
    ord = [0] * q
    for i in range(q):
        ord[i] = int(input())
        ord[i] -= 1
    l = 0
    r = q + 1
    while r - l > 1:
        M = (l + r) // 2
        cur = [0] * n
        for i in range(M):
            cur[ord[i]] = 1
        pr = [0] * (n + 1)
        for i in range(n):
            pr[i+1] = pr[i] + cur[i]
        ok = False
        for i in segs:
            if(pr[i[1]] - pr[i[0]] > (i[1] - i[0]) // 2):
                ok = True
                break
        if ok:
            r = M
        else:
            l = M
    if r == q + 1:
        r = -1
    print(r)
    
for _ in range(int(input())):
    solve()
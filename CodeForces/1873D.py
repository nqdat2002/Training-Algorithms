def minmoves(s, k):
    cnt = 0
    i = 0
    n = len(s)

    while i < n:
        if s[i] == 'B':
            cnt += 1
            i += k - 1
        i += 1 

    return cnt

for _ in range (int(input())):
    n, k = map(int, input().split())
    s = input()
    res = minmoves(s, k)
    print(res)

def rev(n):
    res = 0
    while n > 0:
        res = res * 10 + n % 10
        i = n % 10
        n = (n - i) // 10
    return res
for t in range(int(input())):
    n = int(input())
    if n % 7 == 0:
        print(n)
        continue
    cnt = 0
    while cnt < 1000:
        x = rev(n)
        n += x
        if n % 7 == 0:
            print(n)
            break
        cnt += 1
    if cnt == 1000:
        print(-1)
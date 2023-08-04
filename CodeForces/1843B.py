for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    sum = 0
    cnt = 0
    open = False
    for x in a:
        sum += abs(x)
        if x < 0 and not open:
            open = True
            cnt += 1
        if x > 0:
            open = False
    print(sum, cnt)
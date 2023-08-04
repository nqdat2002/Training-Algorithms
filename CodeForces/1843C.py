for _ in range(int(input())):
    n = int(input())
    s = 0
    while n >= 1:
        s += n
        n //= 2
    print(s)
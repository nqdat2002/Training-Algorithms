from collections import Counter
from math import sqrt

for _ in range(int(input())):
    n = int(input())
    d = Counter(map(str, a))
    for i in range(int(input())):
        (x, y) = map(int, input().split())
        if x * x - 4 * y < 0:
            print(0)
            continue
        D = int(sqrt(x * x - 4 * y))
        x1 = (x + D) // 2
        x2 = (x - D) // 2
        if x1 + x2 != x or x1 * x2 != y:
            print(0)
            continue
        if x1 != x2:
            print(d[str(x1)] * d[str(x2)])
        else:
            print(d[str(x1)] * (d[str(x1)] - 1) // 2)
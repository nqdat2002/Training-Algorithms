from math import gcd
 
 
def lcm(a, b):
    return a * b // gcd(a, b)
 
def range_sum(l, r):
    if l > r:
        return 0
    return (l + r) * (r - l + 1) // 2
 
 
for _ in range(int(input())):
    n, x, y = map(int, input().split())
    l = lcm(x, y)
    pluss = n // x - n // l
    minuss = n // y - n // l
    print(range_sum(n - pluss + 1, n) - range_sum(1, minuss))
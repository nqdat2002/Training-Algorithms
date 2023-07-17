from math import isqrt

p = [True] * 100001
mod = 10**9 + 7

def sieve():
    p[0] = p[1] = False
    for i in range(2, isqrt(100000) + 1):
        if p[i]:
            for j in range(i * i, 100001, i): p[j] = False

def count(n):
    cnt = 1
    for i in range(2, n+1):
        if p[i]:
            exp = 1
            while n // (i**exp) > 0:
                exp += 1
            cnt = (cnt * exp) % mod
    return cnt

sieve()
for t in range(int(input())):
    print(count(int(input())))
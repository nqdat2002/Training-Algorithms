from math import *

def lamtron(s):
    if len(s) == 1:
        return s
    else:
        a = list(int(x) for x in s)
        for i in range(len(a)-1, 0 ,-1):
            if a[i] >= 5:
                a[i-1] += 1
            a[i] = 0
        if a[0] == 10:
            a[0] = 0
            a = [1] + a
        s = ""
        for x in a:
            s += str(x)
        return s


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        print(lamtron(s))
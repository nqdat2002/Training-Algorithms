from math import *

n = int(input())
a = list(map(int, input().split()))
cnt = [0] * 200001
ok = False
for x in a:
    cnt[x] += 1
for x in range(1, n + 1):
    if(cnt[x] == 0):
        print(x)
        ok = True
        break;
if ok == False:
    print(n + 1)


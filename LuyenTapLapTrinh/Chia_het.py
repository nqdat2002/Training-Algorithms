n, m = map(int, input().split())
a = [int(x) for x in input().split()]
res = []
mul = 1
for x in a:
    mul *= x
for i in range(0, m):
    b = [int(x) for x in input().split()]
    mulb = 1
    for x in b:
        mulb *= x
    if mul % mulb == 0:
        res.append(i + 1)
print(len(res))
for i in res:
    print(i, end = ' ')


def getX(l, r, x, y):
    l = max(l, 0)
    r = min(r, x)
    return r - l + 1

def getY(l, r, x, y):
    l = max(l, 0)
    r = min(r, y)
    return  r - l + 1

def Solve(a, b, x, y):
    res = 0
    res += getX(a - b, a - b + y, x, y) * getY(a + b - x, a + b, x, y) - 1
    res += getX(a + b - y, a + b, x, y) * getY(b - a, b - a + x, x, y) - 1
    return res

t = int(input())
while t > 0:
    t -= 1
    # Solve 1:
    # res = 0
    # x, y = map(int, input().split())
    # for i in range (x + 1):
    #     for j in range(y + 1):
    #         res += Solve(i, j, x, y);
    # print(res // 2)
    
    # Solve 2:
    res = 0
    a, b = map(int, input().split())
    for i in range (1, a + 1):
        for j in range(1, i + 1):
            x = i
            y = i + j
            if y > b:
                break
            tmp = 4
            if i == j: tmp = 2
            res += tmp * (a - x + 1) * (b - y + 1)
    for i in range (1, b + 1):
        for j in range(1, i + 1):
            x = i
            y = i + j
            if y > a:
                break
            tmp = 4
            if i == j: tmp = 2
            res += tmp * (b - x + 1) * (a - y + 1)
    for i in range(1, min(a, b) + 1):
        res += 4 * (a - i + 1) * (b - i + 1)
    print(res)
    
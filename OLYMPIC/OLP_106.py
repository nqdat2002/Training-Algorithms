import math
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def Left_index(points):

    minn = 0
    for i in range(1, len(points)):
        if points[i].x < points[minn].x:
            minn = i
        elif points[i].x == points[minn].x:
            if points[i].y > points[minn].y:
                minn = i
    return minn


class Triangle:
    def __init__(self, x1, y1, x2, y2, x3, y3):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.x3 = x3
        self.y3 = y3

    def isTriangle(self):
        return self.x1 * (self.y2 - self.y3) + self.x2 * (self.y3 - self.y1) + self.x3 * (self.y1 - self.y2) != 0.0

    def perimeter(self):
        p1, p2, p3 = [self.x1, self.y1], [self.x2, self.y2], [self.x3, self.y3]
        return math.dist(p1, p2) + math.dist(p2, p3) + math.dist(p1, p3)
    
    def area(self):
        p1, p2, p3 = [self.x1, self.y1], [self.x2, self.y2], [self.x3, self.y3]
        a, b, c = math.dist(p1, p2), math.dist(p2, p3), math.dist(p1, p3)
        p = float((a + b + c) / 2)
        return math.sqrt(p * (p - a) * (p - b) * (p - c))

def orientation(p, q, r):
    val = (q.y - p.y) * (r.x - q.x) - \
        (q.x - p.x) * (r.y - q.y)

    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2


def convexHull(points, n):
    if n < 3:
        return
    l = Left_index(points)
    hull = []
    p = l
    q = 0
    while (True):
        hull.append(p)
        q = (p + 1) % n

        for i in range(n):
            if (orientation(points[p], points[i], points[q]) == 2):
                q = i
        p = q
        if (p == l):
            break
    xx = []
    yy = []
    for each in hull:
        xx.append(points[each].x)
        yy.append(points[each].y)
    res = 0.0
    ll = len(xx)
    for i in range(1, ll - 1):
        nmc = Triangle(xx[0], yy[0], xx[i], yy[i], xx[i + 1], yy[i + 1])
        res += nmc.area()
    
    print("%.3f" % (res))

t = int(input())
for k in range(t):
    n = int(input())
    points = []
    for i in range (n):
        x, y = map(int, input().split())
        points.append(Point(x, y))
    convexHull(points, len(points))

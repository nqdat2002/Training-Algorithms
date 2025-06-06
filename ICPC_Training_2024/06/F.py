import math
from collections import deque

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def isPossible(points, d):
    n = len(points)
    visited = [False] * n
    queue = deque([0]) 
    visited[0] = True
    count = 1
    
    while queue:
        u = queue.popleft()
        for v in range(n):
            if not visited[v] and distance(points[u], points[v]) <= d:
                visited[v] = True
                queue.append(v)
                count += 1
    
    return count == n

def find_minimum_d(points):
    left, right = 0, 2 * 10**9
    
    while right - left > 1e-7:
        mid = (left + right) / 2
        if isPossible(points, mid):
            right = mid
        else:
            left = mid
    
    return right

n = int(input())
points = [(0, 0)]
for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))
res = find_minimum_d(points)
print(f"{res:.6f}")

n, k = map(int, input().split())
nn = 2
z = [[0]*nn for i in range(nn)]


def mul(x, y):
    r = [i.copy() for i in z]
    for i in range(nn):
        for j in range(nn):
            for kk in range(nn): r[i][j] += x[i][kk]*y[kk][j]
            r[i][j]%=10
    return r

I = [[0]*nn for _ in range(nn)]

for i in range(nn): I[i][i] = 1

def pow(A, B):
    if B==0: return I
    if B&1: return mul(A, pow(A, B-1))
    p = pow(A, B>>1)
    return mul(p, p)

if n == 2: print(1 % k)
elif n == 3: print(2 % k)
else:
    a = []
    b = []
    r1 = [3, -1]
    r2 = [1, 0]
    r3 = [1, 0]
    r4 = [2, 0]
    a.append(r1)
    a.append(r2)
    b.append(r3)
    b.append(r4)
    a = pow(a, n - 1)
    c = mul(a, b)
    while c[0][0] < 0: c[0][0] += k
    print(c[0][0])

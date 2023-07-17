def ss(n):
    for i in s:
        if i!='0' and i!='1' and i!='2':
            return False
    return True

for t in range(int(input())):
    s = input()
    if ss(s):
        print("YES")
    else:
        print("NO")
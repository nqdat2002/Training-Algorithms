n, k = map(int, input().split())
cnt = 0
s = ''
for i in range (1, n + 1):
	s = s + str(i)
	if int(s) % k == 0:
		cnt += 1
print(cnt)
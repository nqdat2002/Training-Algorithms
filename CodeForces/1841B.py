for _ in range(int(input())):
	q = int(input())
	a = []
	cnt = 0
	for x in map(int, input().split()):
		nw_cnt = cnt + (len(a) > 0 and a[-1] > x)
		if nw_cnt == 0 or (nw_cnt == 1 and x <= a[0]):
			a.append(x)
			cnt = nw_cnt
			print('1', end="")
		else:
			print('0', end="")
	print()
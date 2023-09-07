import math

for _ in range(int(input())):
	s = input()
	a = s[::-1]

	_gcd = math.gcd(int(a), int(s))
	_lcm = int(a) * int(s) // _gcd
	print(a)
	print(_gcd)
	print(_lcm)

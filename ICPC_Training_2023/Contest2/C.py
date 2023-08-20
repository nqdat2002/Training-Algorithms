s = str(input())
sum = 0
n = len(s)
for i in range(n):
	sum += (ord(s[n - i - 1]) - 48) * pow(1.5, i)
	
from fractions import Fraction
tu = Fraction(sum).numerator
mau = Fraction(sum).denominator
if tu % mau == 0: print(tu // mau)
else:
    nguyen = tu // mau
    du = tu - nguyen * mau
    print(nguyen, end = ' ')
    print(du, '/', mau, sep = '')

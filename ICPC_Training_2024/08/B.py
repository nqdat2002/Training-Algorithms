def findPos(p, q, x):
    integer_part = p // q
    remainder = p % q
    s = str(integer_part)
    if remainder != 0:
        s += "."
        fraction_part = ""
        seen_remainders = {}
        pos = 0
        while remainder != 0 or len(fraction_part) < len(x):
            if remainder in seen_remainders:
                break
            seen_remainders[remainder] = pos
            remainder *= 10
            fraction_part += str(remainder // q)
            remainder %= q
            pos += 1
        s += fraction_part
    s = s.replace(".", "")

    index = s.find(x)
    return index + 1 if index != -1 else 0

P, Q = map(int, input().split())
X = input()
print(findPos(P, Q, X))

def count_zero_bits(n, k):
    count = 0
    for i in range(n + 1):
        binary = bin(i)[2:]
        if binary.count('0') == k:
            count += 1
    return count

T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    print(count_zero_bits(N, K))

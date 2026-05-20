#include <stdio.h>
#include <math.h>

typedef long long ll;
ll count_divisors(ll n) {
    if (n < 1) return 0;
    ll count = 0, i;
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i * i != n) {
                count++;
            }
        }
    }
    return count;
}
ll power(ll n, int k) {
    ll res = 1, i;
    for ( i = 0; i < k; i++) {
        if (__builtin_mul_overflow(res, n, &res)) return -1;
    }
    return res;
}

int main() {
    ll X, i, k;
    if (scanf("%lld", &X) != 1) return 0;

    if (X == 1) {
        printf("1\n");
        return 0;
    }

    ll min_n = -1;
    for ( k = 2; k <= 60; k++) {
        ll n = (ll)round(pow(X, 1.0 / k));
        
        if (n < 1) continue;

        if (power(n, k) == X) {
            if (count_divisors(n) == k) {
                if (min_n == -1 || n < min_n) {
                    min_n = n;
                }
            }
        }
    }
    printf("%lld\n", min_n);

    return 0;
}


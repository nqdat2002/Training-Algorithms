#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
long long result(long long a[], int n) {
    qsort(a, n, sizeof(long long), compare);
    int i;
    long long res = 0;
    for (i = 0; i < n; i++) {
        res += (long long)i * a[i] - (long long)(n - 1 - i) * a[i];
    }
    return res;
}
int main() {
    int n, i;
    scanf("%d", &n);
    long long *a = (long long*)malloc(n * sizeof(long long));
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long ans = result(a, n);
    printf("%lld\n", ans);
    free(a);
    return 0;
}

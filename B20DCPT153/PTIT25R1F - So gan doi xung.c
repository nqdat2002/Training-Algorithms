#include <stdio.h>
int check(int n) {
    int digits[10], len, i;
    while (n > 0) {
        digits[len++] = n % 10;
        n /= 10;
    }
    int cnt = 0;
    for (i = 0; i < len / 2; i++) {
        if (digits[i] != digits[len - 1 - i]) {
            cnt++;
        }
    }
    return (cnt <= 1);
}
void result(int T, int A[], int B[], int res[]) {
    int *pref = (int*)malloc((1000001) * sizeof(int));
    pref[0] = 0;
    int i;
    for (i = 1; i <= 1000000; i++) pref[i] = pref[i - 1] + (check(i) ? 1 : 0);
    for (i = 0; i < T; i++) res[i] = pref[B[i]] - pref[A[i] - 1];
    free(pref);
}
int main() {
    int t, i;
    scanf("%d", &t);
    int A[100005], B[100005];
    for (i = 0; i < t; i++) scanf("%d %d", &A[i], &B[i]); 
    int res[100005];
    result(t, A, B, res);
    for (i = 0; i < t; i++) printf("%d\n", res[i]);
    return 0;
}

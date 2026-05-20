#include <stdio.h>
long long result(char s[], int n) {
    long long cnt = 0, len = 1;
    int i;
    for (i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            len++;
        } else {
            cnt += (len * (len - 1)) / 2;
            len = 1;
        }
    }
    cnt += (len * (len - 1)) / 2;
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[300005];
    scanf("%s", s);
    long long res = result(s, n);
    printf("%lld\n", res);
    return 0;
}

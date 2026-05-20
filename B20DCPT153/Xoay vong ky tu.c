#include <stdio.h>
#include <string.h>
void Try(char a[]) {
    int n = strlen(a), i;
    char c[55];
    strcpy(c, a);
    for (i = 1; i < n; i++) a[i - 1] = c[i];
    a[n - 1] = c[0];
}
int xuLy(char a[][55], int n) {
	char s[55], x[55];
	strcpy(s, a[0]);
    int ok = 1, ans = 1e9, i, j, m = strlen(s);
    for (i = 0; i < m; i++) {
        int d = 0;
        for (j = 0; j < n; j++) {
            int k;
            strcpy(x, a[j]);
            for (k = 0; k < m; k++) {
                if (strcmp(x, s) == 0) {
                    d += k;
                    break;
                }
                Try(x);
            }
            if (k == m) {
                ok = 0;
                break;
            }
        }
        if (d < ans)
            ans = d;
        Try(s);
    }
    if (!ok) return -1;
    return ans;
}
int main() {
    int n, i;
    scanf("%d", &n);
    char a[100][55];
    for (i = 0; i < n; i++) scanf("%s", a[i]);
    int ans = xuLy(a, n);
    printf("%d", ans);
    return 0;
}

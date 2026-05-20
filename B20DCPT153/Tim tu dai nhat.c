#include <stdio.h>
#include <string.h>
int result(char a[][50], int n, int *maxLen, int cnt[]) {
    *maxLen = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        int len = strlen(a[i]);
        if (len > *maxLen)
            *maxLen = len;
    }
    for (i = 0; i < n; i++) {
        cnt[i] = 1;
        for (j = i + 1; j < n; j++) {
            if (strcmp(a[i], a[j]) == 0) {
                cnt[i]++;
                a[j][0] = 0;
            }
        }
    }
    return 0;
}
int main() {
    char a[10000][50];
    int n = 0, i;
    while (scanf("%s", a[n]) != EOF) {
        n++;
    }
    int maxLen, cnt[10000];
    result(a, n, &maxLen, cnt);
    for ( i = 0; i < n; i++) {
        if (a[i][0] != 0 && strlen(a[i]) == maxLen) {
            printf("%s %d %d\n", a[i], maxLen, cnt[i]);
        }
    }
    return 0;
}

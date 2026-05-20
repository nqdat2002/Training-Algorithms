#include <stdio.h>
#include <string.h>
int check(char a[]) {
    int n = strlen(a);
    for (int i = 0; i <= (n - 1) / 2; i++)
        if (a[i] != a[n - i - 1])
            return 0;
    return 1;
}
int result(char input[][50], int n, char res[][50], int cnt[]) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (check(input[i])) {
            int len = strlen(input[i]);
            if (len > max) max = len;
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (check(input[i]) && strlen(input[i]) == max) {
            int ok = 1;
            for (int t = 0; t < k; t++) {
                if (strcmp(res[t], input[i]) == 0) {
                    cnt[t]++;
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                strcpy(res[k], input[i]);
                cnt[k] = 1;
                k++;
            }
        }
    }
    return k;
}

int main() {
    char input[10000][50];
    int n = 0, i;
    while (scanf("%s", input[n]) != EOF) {
        n++;
    }
    char res[10000][50];
    int cnt[10000];
    int k = result(input, n, res, cnt);
    for (i = 0; i < k; i++) printf("%s %d\n", res[i], cnt[i]);
    return 0;
}

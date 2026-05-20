#include <stdio.h>
#include <string.h>
void result(char s[], char res[]) {
    int n = 0, p = 0, i, j;
    char a[100][100];
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            if (p != 0) {
                a[n][p] = 0;
                n++;
                p = 0;
            }
        } else {
            a[n][p++] = s[i];
        }
    }
    if (p != 0) {
        a[n][p] = 0;
        n++;
    }
    for (i = 1; i < n; i++) {
        if (a[i][0] >= 'a' && a[i][0] <= 'z')
            a[i][0] -= 32;

        for (j = 1; j < strlen(a[i]); j++) {
            if (a[i][j] >= 'A' && a[i][j] <= 'Z')
                a[i][j] += 32;
        }
    }
    for (i = 0; i < strlen(a[0]); i++) {
        if (a[0][i] >= 'a' && a[0][i] <= 'z')
            a[0][i] -= 32;
    }
    res[0] = 0;
    for (i = 1; i < n; i++) {
        if (i > 1) strcat(res, " ");
        strcat(res, a[i]);
    }
    strcat(res, ", ");
    strcat(res, a[0]);
}
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char s[100], res[200];
        gets(s);
        result(s, res);
        printf("%s\n", res);
    }
    return 0;
}

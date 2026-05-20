#include <stdio.h>
#include <string.h>
int result(char s1[], char s2[], char res[][100]) {
    int n1 = 0, p1 = 0, n2 = 0, p2 = 0, i, j;
    char a[100][100], b[100][100];
    int m1 = strlen(s1), m2 = strlen(s2);
    for (i = 0; i < m1; i++) {
        if (s1[i] == ' ') {
            a[n1][p1] = 0;
            n1++;
            p1 = 0;
        }
		else {
            a[n1][p1++] = s1[i];
        }
    }
    a[n1][p1] = 0;
    for (i = 0; i < m2; i++) {
        if (s2[i] == ' ') {
            b[n2][p2] = 0;
            n2++;
            p2 = 0;
        }
		else {
            b[n2][p2++] = s2[i];
        }
    }
    b[n2][p2] = 0;
    for (i = 0; i <= n1; i++) {
        for (j = i + 1; j <= n1; j++) {
            if (strcmp(a[i], a[j]) == 0)
                a[j][0] = 0;
        }
    }
    for (i = 0; i <= n1; i++) {
        for (j = i + 1; j <= n1; j++) {
            if (strcmp(a[i], a[j]) > 0) {
                char x[100];
                strcpy(x, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], x);
            }
        }
    }
    int k = 0;
    for (i = 0; i <= n1; i++) {
        if (a[i][0] == 0) continue;
        int ok = 1;
        for (j = 0; j <= n2; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            strcpy(res[k++], a[i]);
        }
    }
    return k;
}
int main() {
    char s1[200], s2[200];
    char res[100][100];
    gets(s1);
    gets(s2);
    int n = result(s1, s2, res), i;
    for (i = 0; i < n; i++) {
        printf("%s ", res[i]);
    }
    return 0;
}

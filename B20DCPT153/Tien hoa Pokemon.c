#include <stdio.h>
#include <string.h>
int sum(int k, int m) {
    int c = 0;
    while (m / k > 0) {
        int a = m / k;
        c += a;
        m = m - a * k + a * 2;
    }
    return c;
}
void result(int n, char name[][100], int k[], int m[], char ansname[], int *tong) {
    int max = 0, i;
    *tong = 0;
    for (i = 0; i < n; i++) {
        int c = sum(k[i], m[i]);
        if (c > max) {
            strcpy(ansname, name[i]);
            max = c;
        }
        *tong += c;
    }
}
int main() {
    int n, i;
    scanf("%d", &n);
    char name[100][100];
    int k[100], m[100];
    for (i = 0; i < n; i++) {
        scanf("%s%d%d", name[i], &k[i], &m[i]);
    }
    char ansname[100];
    int tong;
    result(n, name, k, m, ansname, &tong);
    printf("%d\n%s", tong, ansname);
    return 0;
}

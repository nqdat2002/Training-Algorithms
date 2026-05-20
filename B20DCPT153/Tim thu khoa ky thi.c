#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[100];
    char date[100];
    double mark1, mark2, mark3;
    double marksum;
};
int result(struct Student a[], int n, struct Student res[]) {
    double max = 0;
    int i;
    for (i = 1; i <= n; i++) {
        a[i].marksum = a[i].mark1 + a[i].mark2 + a[i].mark3;
        if (a[i].marksum > max)
            max = a[i].marksum;
    }
    int k = 0;
    for (i = 1; i <= n; i++) {
        if (a[i].marksum == max) {
            res[k++] = a[i];
        }
    }
    return k;
}

int main() {
    int n, i;
    scanf("%d", &n);
    struct Student a[n + 1], res[n + 1];
    for (i = 1; i <= n; i++) {
        scanf("\n");
        a[i].id = i;
        gets(a[i].name);
        gets(a[i].date);
        scanf("%lf%lf%lf", &a[i].mark1, &a[i].mark2, &a[i].mark3);
    }
    int k = result(a, n, res);
    for (i = 0; i < k; i++) {
        printf("%d %s %s %.1lf\n",
               res[i].id, res[i].name, res[i].date, res[i].marksum);
    }
    return 0;
}

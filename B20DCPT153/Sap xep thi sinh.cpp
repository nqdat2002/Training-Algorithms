#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[100];
    char date[100];
    double mark1, mark2, mark3;
    double marksum;
};
int cmp(struct Student a, struct Student b) {
    return a.marksum < b.marksum;
}
void swap(struct Student *a, struct Student *b) {
    struct Student c = *a;
    *a = *b;
    *b = c;
}
void solve(struct Student a[], int n) {
    for (int i = 1; i <= n; i++) {
        a[i].marksum = a[i].mark1 + a[i].mark2 + a[i].mark3;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (cmp(a[i], a[j])) {
                swap(&a[i], &a[j]);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    struct Student a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("\n");
        a[i].id = i;
        gets(a[i].name);
        gets(a[i].date);
        scanf("%lf%lf%lf", &a[i].mark1, &a[i].mark2, &a[i].mark3);
    }
    solve(a, n);
    for (int i = 1; i <= n; i++) {
        printf("%d %s %s %.1lf\n", a[i].id, a[i].name, a[i].date, a[i].marksum);
    }
    return 0;
}

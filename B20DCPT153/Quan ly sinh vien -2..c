#include <stdio.h>
#include <string.h>
struct Student {
    int msv;
    char name[100];
    float a, b, c;
    float sum;
};
void add(struct Student f[], int n) {
	int i;
    for (i = 1; i <= n; i++) {
        f[i].msv = i;
        f[i].sum = f[i].a + f[i].b + f[i].c;
    }
}
void change(struct Student f[], int d, char name[], float a, float b, float c) {
    strcpy(f[d].name, name);
    f[d].a = a;
    f[d].b = b;
    f[d].c = c;
    f[d].sum = a + b + c;
}
int check(struct Student f[], int n, int idx[]) {
    int k = 0, i;
    for (i = 1; i <= n; i++) {
        if (f[i].a < f[i].b && f[i].b < f[i].c) {
            idx[k++] = i;
        }
    }
    return k;
}
int main() {
    int n = 0, i;
    struct Student f[100];
    while (1) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d", &n);
            for (i = 1; i <= n; i++) {
                f[i].msv = i;
                scanf("\n%[^\n]", f[i].name);
                scanf("%f%f%f", &f[i].a, &f[i].b, &f[i].c);
            }
            add(f, n);
            printf("%d\n", n);
        }
        else if (x == 2) {
            int m;
            scanf("%d", &m);
            char name[100];
            float a, b, c;
            scanf("\n%[^\n]", name);
            scanf("%f%f%f", &a, &b, &c);
            change(f, m, name, a, b, c);
            printf("%d\n", m);
        }
        else {
            int idx[100];
            int k = check(f, n, idx);
            for (i = 0; i < k; i++) {
                int t = idx[i];
                printf("%d %s %.1f %.1f %.1f\n",
                       f[t].msv, f[t].name,
                       f[t].a, f[t].b, f[t].c);
            }
            return 0;
        }
    }
}

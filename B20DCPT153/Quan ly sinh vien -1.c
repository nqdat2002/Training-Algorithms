#include <stdio.h>
#include <string.h>

struct Student {
    int msv;
    char name[100];
    float a, b, c;
};
void add(int n, struct Student f[]) {
	int i;
    for (i = 1; i <= n; i++) {
        f[i].msv = i;
    }
}
void change(int d, struct Student f[], char name[], float a, float b, float c) {
    strcpy(f[d].name, name);
    f[d].a = a;
    f[d].b = b;
    f[d].c = c;
}
int main() {
	int n = 0, i;
    struct Student f[100];
    while (1) {
        int x;
        scanf("%d", &x);

        if (x == 1) {
            scanf("%d", &n);
            add(n, f);
            for (i = 1; i <= n; i++) {
                scanf("\n%[^\n]", f[i].name);
                scanf("%f%f%f", &f[i].a, &f[i].b, &f[i].c);
            }
            printf("%d\n", n); 
        }
        else if (x == 2) {
            int m;
            scanf("%d", &m);
            char name[100];
            float a, b, c;
            scanf("\n%[^\n]", name);
            scanf("%f%f%f", &a, &b, &c);
            change(m, f, name, a, b, c);
            printf("%d\n", m);
        }
        else {
            for (i = n; i >= 1; i--) {
                printf("%d %s %.1f %.1f %.1f\n",
                       f[i].msv, f[i].name,
                       f[i].a, f[i].b, f[i].c);
            }
            return 0;
        }
    }
}

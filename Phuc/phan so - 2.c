#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void reduce(int *num, int *den) {
    int g = gcd(*num, *den);
    *num /= g;
    *den /= g;
}

void quyDong(int a, int b, int c, int d, int *a1, int *c1, int *common) {
    *common = b * d / gcd(b, d);  
    *a1 = a * (*common / b);     
    *c1 = c * (*common / d); 
}

void tong(int a, int b, int c, int d, int *num, int *den) {
    *num = a * d + b * c; 
    *den = b * d;         
    reduce(num, den);     
}

void thuong(int a, int b, int c, int d, int *num, int *den) {
    *num = a * d;  
    *den = b * c;  
    reduce(num, den);
}

int main() {
    int T;
    scanf("%d", &T);  
    for (int t = 1; t <= T; t++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        reduce(&a, &b);
        reduce(&c, &d);

        int a1, c1, common;
        quyDong(a, b, c, d, &a1, &c1, &common);

        printf("Case #%d:\n", t);
        printf("%d/%d %d/%d\n", a1, common, c1, common); 

        int sum_num, sum_den;
        tong(a, b, c, d, &sum_num, &sum_den);  
        int div_num, div_den;
        thuong(a, b, c, d, &div_num, &div_den);  

        printf("%d/%d\n", sum_num, sum_den);
        printf("%d/%d\n", div_num, div_den);
    }
    return 0;
}

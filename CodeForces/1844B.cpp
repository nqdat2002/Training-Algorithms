#include <bits/stdc++.h>
using namespace std;

int a[200000];
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) printf("1\n");
        else if (n == 2) printf("1 2\n");
        else {
            int c = 4;
            fill(a, a + n, 0);
            a[0] = 2, a[n / 2] = 1, a[n - 1] = 3;
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) a[i] = c++;
            }
            for (int i = 0; i < n; i++) printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
        }
    }
    return 0;
}
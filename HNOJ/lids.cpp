#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000010
int a[N], b[N], f[N], n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int c[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i], c[i] = a[i];
    int m = 0, mm = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        m = max(m, f[i]);
        b[f[i]] = a[i];
    }
    reverse(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = lower_bound(b + 1, b + mm + 1, c[i]) - b;
        mm = max(mm, f[i]);
        b[f[i]] = c[i];
    }
    cout << n - max(m, mm) << endl;
    return 0;
}

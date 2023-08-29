#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, p[20];
ll a, b, res;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];

    res = LONG_LONG_MAX;
    for (int i = 0; i < (1 << n); i++) {
        a = 0; b = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) a += p[j];
            else b += p[j];
        }
        res = min(res, abs(a - b));
    }
    cout << res << endl;
}
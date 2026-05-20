#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ld x, y, r;
    cin >> x >> y >> r;
    ll res = 0, eps = 1e-10;
    ll x_start = ceill(x - r - eps);
    ll x_end = floorl(x + r + eps);
    for (ll i = x_start; i <= x_end; ++i) {
        ld dx = (ld)i - x;
        ld dy_squared = r * r - dx * dx;
        if (dy_squared >= 0) {
            ld dy = sqrtl(dy_squared);
            ll y_min = ceill(y - dy - eps);
            ll y_max = floorl(y + dy + eps);

            if (y_max >= y_min) {
                res += (y_max - y_min + 1);
            }
        }
    }
    cout << res << endl;
    return 0;
}

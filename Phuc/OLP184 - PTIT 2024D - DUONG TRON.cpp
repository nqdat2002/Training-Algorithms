#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    double x_db, y_db, r_db;
    cin >> x_db >> y_db >> r_db;
    ll X = llround(x_db * 10000);
    ll Y = llround(y_db * 10000);
    ll R = llround(r_db * 10000);
    ll R2 = R * R;
    
    ll res = 0;
    ll x_min = ceil(x_db - r_db);
    ll x_max = floor(x_db + r_db);
    
    for (ll x = x_min; x <= x_max; ++x) {
        ll dx = x * 10000 - X;
        ll rem2 = R2 - dx * dx; 
        if (rem2 >= 0) {
            ll dy = sqrt(rem2);
            while ((dy + 1) * (dy + 1) <= rem2) dy++;
            while (dy * dy > rem2) dy--;
            ll y1 = Y - dy;
            ll y2 = Y + dy;
            ll y_min = (y1 > 0) ? (y1 + 9999) / 10000 : y1 / 10000;
            ll y_max = (y2 >= 0) ? y2 / 10000 : (y2 - 9999) / 10000;
            
            if (y_min <= y_max) {
                res += (y_max - y_min + 1);
            }
        }
    }
    cout << res << "\n";
    return 0;
}

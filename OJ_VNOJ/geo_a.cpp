#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pi 3.1415926535897932384626433
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x, y;
    cin >> x >> y;
    if (y == 0){
        if(x > 0) {
            cout << fixed << setprecision(10) << (double)pi/2 << endl;
            return 0;
        }
        else{
            cout << fixed << setprecision(10) << -(double)pi/2 << endl;
            return 0;
        }
    }
    if(x < 0 && y < 0){
        x = abs(x);
        y = abs(y);
        double dxy = 1.0 * (x * x) / (x * (double) sqrt((ll)x * x + (ll)y * y));
        cout << fixed << setprecision(10) << acos(dxy) + pi << endl;
    }
    else {
        double dxy = 1.0 * (x * x) / (x * (double) sqrt((ll)x * x + (ll)y * y));
        cout << fixed << setprecision(10) << acos(dxy) << endl;
    }
    return 0;
}
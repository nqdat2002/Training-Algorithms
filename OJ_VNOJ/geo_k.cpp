#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(6) <<(double) sqrt((ll)((x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2))) << endl;
    return 0;
}

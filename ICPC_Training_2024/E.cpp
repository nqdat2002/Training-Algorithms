#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[200005], f[200005];
main() {
    int n; ll c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, LONG_LONG_MAX, sizeof(f));
    f[1] = 0;
    f[2] = (ll) pow(a[2] - a[1], 2) + c;
    for (ll i = 2; i <= n; i++) {
        // while (id < i - 1 && (ll) pow(a[i] - a[id], 2) >= c * (i - id))
        // {
        //     id++;
        // }
        f[i] = min(f[i - 1] + (ll) pow(a[i] - a[i - 1], 2) + c, f[i - 2] + (ll) pow(a[i] - a[i - 2], 2) + c);
    }
    cout << f[n] << endl;
}
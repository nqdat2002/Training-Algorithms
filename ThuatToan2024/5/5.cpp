// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main() {
//     int t; cin >> t;
//     while (t--) {
//         ll n, k;  cin >> n >> k;
//         vector<ll> a(n);
//         for (auto& x : a) cin >> x;
//         int res = n + 1, l = 0;
//         ll curr = 0;
//         for (int r = 0; r < n; ++r) {
//             curr = __gcd(curr, a[r]);
//             while (curr == k) {
//                 res = min(res, r - l + 1);
//                 curr = __gcd(curr, a[++l]);
//             }
//         }
//         cout << ((res == n + 1) ? -1 : res) << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (auto &x: a) cin >> x;
        int res = n + 1;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            for (int j = i; j < n; ++j) {
                x = __gcd(x, a[j]);
                if (x == k) {
                    res = min(res, j - i + 1);
                    break;
                } else if (x < k) break;
                
            }
        }
        if (res == n + 1)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
}

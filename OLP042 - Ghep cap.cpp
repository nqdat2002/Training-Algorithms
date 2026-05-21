#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1000000;
int d[MAXN + 1];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            d[j]++;
        }
    }
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, int> primeFactor(ll k) {
    map<int, int> prime;
    for (int i = 2; i <= sqrt(k); ++i) {
        while (k % i == 0) {
            prime[i]++;
            k /= i;
        }
    }
    if (k > 1) prime[k]++;
    return prime;
}
ll count(int n, int p) {
    int res = 0;
    while (n > 0) {
        n /= p;
        res += n;
    }
    return res;
}
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        map<int, int> factors = primeFactor(k);
        ll res = INT_MAX;
        for (const auto& f : factors) {
            int p = f.first;
            int a = f.second;
            res = min(res, count(n, p) / a);
        }
        cout << res << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 100;

ll pow(int n, int k) {
    if (k == 0)
        return 1;
    ll tmp = pow(n, k / 2);
    if (k % 2 == 0)
        return (tmp % mod) * (tmp % mod) % mod;
    return ((tmp % mod) * (tmp % mod) % mod) * (n % mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long x = n * pow(2, k) - n * (pow(2, k) - 1) / 99;
        cout << x << endl;
    }

    return 0;
}
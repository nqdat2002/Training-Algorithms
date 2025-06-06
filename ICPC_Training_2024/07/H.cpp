#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 20000001;
vector<bool> prime(20000001, 1);
vector<int> factor;
void SieveOfAtkin(int limit){
    vector<int> sieve(limit, 0);
 
    if (limit > 2)
        sieve[2] = 1;
    if (limit > 3)
        sieve[3] = 1;
    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {
 
            int n = (4 * x * x) + (y * y);
            if (n <= limit 
                && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= 1;
 
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= 1;
 
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit 
                && n % 12 == 11)
                sieve[n] ^= 1;
        }
    }
    factor.push_back(2);
    factor.push_back(3);
    for (int r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            factor.push_back(r);
            for (int i = r * r; i < limit; i += r * r)
                sieve[i] = 0;
        }
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    SieveOfAtkin(nmax);
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != 0 && a[i + 1] != 0 && __gcd(a[i], a[i + 1]) != 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    // cout << factor.size() << endl;
    // for (auto x: factor) cout << x << " ";

    for (int x : factor) {
        bool valid = true;
        for (int i = 0; i < n - 1; ++i) {
            int B1 = (a[i] == 0) ? x : a[i];
            int B2 = (a[i + 1] == 0) ? x : a[i + 1];
            if (__gcd(B1, B2) != 1) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}

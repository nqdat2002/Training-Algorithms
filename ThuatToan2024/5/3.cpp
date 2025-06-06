#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 10000001;
vector<bool> prime(nmax, 1);
vector<int> factor;
void sieve() {
    factor.clear();
    prime[0] = prime[1] = 0;
    for (ll i = 2; i <= nmax; i++) {
        if (prime[i]) {
            factor.push_back(i);
            for (ll j = i * i; j <= nmax; j += i) 
                prime[j] = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (ll i = 0; i < (int)factor.size(); i++) {
            if (factor[i] * factor[i] > n) break;
            if (prime[factor[i]] && n % factor[i] == 0) {
                ll cnt = 0;
                while (n % factor[i] == 0) {
                    cnt += 1;
                    n /= factor[i];
                }
                cout << factor[i] << " " << cnt << endl;
            }
        }
        if (n > 1) cout << n << " " << 1 << endl;
        cout << endl;
    }
    return 0;
}

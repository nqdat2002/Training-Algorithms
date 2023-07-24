#include <bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define All(v) (v).begin(),(v).end()
#define reset(x) memset((x),0,sizeof((x)))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
// mt19937 rng(1);
// mt19937_64 rng(1);

vector<bool> prime(100000001, 1);
vector<int> factor;
void sieve() {
    factor.clear();
    prime[0] = prime[1] = 0;
    for (ll i = 2; i <= 10000000; i++) {
        if (prime[i]) {
            factor.push_back(i);
            for (ll j = i * i; j <= 10000000; j += i) prime[j] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        for (ll i = 0; i < factor.size(); i++) {
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

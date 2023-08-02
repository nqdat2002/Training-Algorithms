#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

vector<bool> prime(1e9 + 1, 1);
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


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // sieve();

    int t; cin >> t;

    while (t--) {
        // ll n; cin >> n;
        // vector<pair<int, int > > v;
        // for (ll i = 0; i < factor.size(); i++) {
        //     if (factor[i] * factor[i] > n) break;
        //     if (prime[factor[i]] && n % factor[i] == 0) {
        //         ll cnt = 0;
        //         while (n % factor[i] == 0) {
        //             cnt += 1;
        //             n /= factor[i];
        //         }
        //         cout << factor[i] << " " << cnt << endl;
        //         v.push_back({factor[i], cnt});
        //     }
        // }
        // if (n > 1) {
        //     cout << n << " " << 1 << endl;
        //     v.push_back({n, 1});
        // }
        // ll r = pow(v.back().first, v.push_back().second);
        ll n; cin >> n;
        int cnt = 0, res = 0;
        for(int i = 1; i <= 1e9; ++i){
            if(n % i == 0){
                cnt ++;
            }else{
                cnt = 0;
            }
            res = max(res, cnt);
        }
        cout << res << endl;
    }
    return 0;
}
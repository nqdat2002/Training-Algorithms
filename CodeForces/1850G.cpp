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

const int maxn = 5005;
const int MOD = 1000000007;
const int base = 31;
const long long MM = 1LL * MOD * MOD;


int main() {
    int t; cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        map<ll, ll> up, side, diag1, diag2;
        ll ans = 0;
        for (int i = 0; i < n; i++){
            ll x, y;
            cin >> x >> y;
            up[x]++;
            side[y]++;
            diag1[x - y]++;
            diag2[x + y]++;
        }
        for (auto x : up){
            ans += x.second * (x.second - 1);
        }
        for (auto x : side){
            ans += x.second * (x.second - 1);
        }
        for (auto x : diag1){
            ans += x.second * (x.second - 1);
        } 
        for (auto x : diag2){
            ans += x.second * (x.second - 1);
        }
        cout << ans << endl;
    }
    return 0;
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<ll, ll> > v(999);

    pair<ll, ll> f1 = {1, 0}, f2 = {0, 1};
    v[1] = f1, v[2] = f2;
    for(ll i = 3; i < 901; ++i){
        f1 = v[i - 2], f2 = v[i - 1];
        v[i].first = f1.first + f2.first;
        v[i].second = f1.second + f2.second;
        f1 = f2;
        f2 = v[i];
    }
    int t; cin >> t;

    while (t--) {
        ll n, k; cin >> n >> k;
        if(k >= 901){
            cout << 0 << endl;
            continue;
        }
        pair<ll, ll> ff = v[k];
        ll ans = 0;
        for(int i = 0; i <= n; ++i){
            ll x = (n - ff.first * i);
            if(x % ff.second == 0){
                if(x / ff.second >= i)
                    ++ ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

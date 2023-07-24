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
    int t; cin >> t;

    while (t--) {
        ll n, k; cin >> n >> k;
        ll a[n];
        for(auto &x: a) cin >> x;
        ll j = 0, res = 1;
        while(k--){
            while(j < n && a[j] <= res + j) ++j;
            res += j;
        }
        cout << res << endl;
    }
    return 0;
}

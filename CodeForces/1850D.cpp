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
    while(t--){
        ll n, k; cin >> n >> k;
        ll ans = 0;
        ll a[n];
        for(auto &x: a) cin >> x;
        sort(a, a + n);
        ll l = 0, r = n;
        while(l < r){
            int m = l + 1;
            while(m < r){
                if(a[m] - a[m - 1] > k) break;
                m ++;
            }
            ans = max(ans, m - l);
            l = m;
        }

        cout << n - ans << endl;
    }
    return 0;
}

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
    while (t--){
        ll n, c;
        cin >> n >> c;
        ll sum2 = 0, sum2x = 0;
        for (int i = 0; i < n; i++){
            ll r; cin >> r;
            sum2 += r * r;
            sum2x += r;
        }

        c -= sum2;
        c = c / (4 * n);
        sum2x /= 2 * n;
        ll res = sqrtl(sum2x * sum2x + c);
        cout << res - sum2x << endl;
    }
    return 0;
}

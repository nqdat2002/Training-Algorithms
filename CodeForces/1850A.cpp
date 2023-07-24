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
        int a[3];
        for(auto &x: a) cin >> x;
        sort(a, a + 3);
        if(a[1] + a[2] >= 10) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}

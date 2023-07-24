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
        string ans = "";
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                char c; cin >> c;
                if(c != '.') ans += c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

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
        int n; cin >> n;
        int a[n];
        int b[n + 1];
        memset(b, 0, sizeof(b));
        map<int, int> mp;
        for(auto &x : a){
            cin >> x;
            if(x <= n) mp[x] ++;
        }
        for(int i = 1; i <= n; ++i){
            if(!mp[i]) continue;
            for(int j = i; j <= n; j += i){
                b[j] += mp[i];
            }
        }
        cout << *max_element(b + 1, b + n + 1) << endl;
    }
    return 0;
}

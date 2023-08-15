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

void solve(int n, int s, int t) {
    if (n == 0) return;
    if (t == (s + 1) % 3) {
        solve(n - 1, s, 3 - s - t);
        cout << char(s + 65);
        solve(n - 1, 3 - s - t, s);
    }
    else {
        solve(n - 1, s, t);
        cout << char(s + 65);
        solve(n - 1, t, s);
        cout << char(3 - s - t + 65);
    }
    solve(n - 1, s, t);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    solve(n, 0, 2);
    cout << endl;
    return 0;
}

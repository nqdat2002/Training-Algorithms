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

const int maxn = 500005;
const int MOD = 1000000007;
const int base = 31;
const long long MM = 1LL * MOD * MOD;

int n;
char a[maxn];
vector < pair < char, char > > v;
int res;

void solve(int n, int des) {
    if (n <= 0) return;
    if (a[n] != des) {
        solve(n - 1, 3 - a[n] - des);
        v.push_back({a[n], des});
        a[n] = des;
    }
    solve(n - 1, des);
}


int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char x;
        cin >> x;
        a[i] = x - 'A';
    }
    solve(n, 2);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        pii x = v[i];
        cout << char(x.fi + 'A') << char(x.se + 'A') << endl;
    }
    return 0;
}

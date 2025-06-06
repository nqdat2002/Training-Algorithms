#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
void Try(string s) {
    if (s.size() > 10) return;
    if (!s.empty()) v.push_back(stoll(s));
    Try(s + "4");
    Try(s + "7");
}
int main() {
    ll a, b; cin >> a >> b;
    Try("");
    sort(v.begin(), v.end());
    ll res = 0, l = a;
    for (ll x : v) {
        if (x < l) continue;
        ll r = min(b, x);
        res += (r - l + 1) * x;
        l = r + 1;
        if (l > b) break;
    }
    cout << res << endl;
    return 0;
}
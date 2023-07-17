#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
const int mod = 1e9 + 7;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define For(i, a, b) for(int i = a; i <= b; i++)
#define RFor(i, a, b) for(int i = a; i >= b; i--)
#define Forr(a, b, c) for(int i = a; i <= b; i+=c)
#define pb push_back
#define fi first
#define se second
#define bit(n, i) ((n>>i)&1)
// #ifndef ONLINE_JUDGE
//   #include "debug.h"
// #else
//   #define debug(...) 42
//   #define debugArr(...) 42
// #endif
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int , null_type, less_equal<int> , rb_tree_tag ,
        tree_order_statistics_node_update>
        ordered_multiset;
#define Maxn 100001
ll ck[20][20], p[20][20];
int a[10], b[10];
ll mul(int id, int mask) {
    ll ans = 1;
    For(i, 0, 9) {
        if (bit(mask, i)) {
            if (b[i] < 0) return 0;
            ans *= ck[id][b[i]];
            id -= b[i];
            if (id < 0) return 0;
        }
    }
    ans *= p[10 - __builtin_popcount(mask)][id];
    return ans;
}
ll solve(string s, int mask) {
    ll ans = 0;
    if (s.size() == 1 && s[0] == '0') return 0;
    For(i, 0, 9) b[i] = a[i];
    int n = s.size();
    For(i, 1, n - 1) {
        For(j, 1, 9) {
            b[j]--;
            ans += mul(i - 1, mask);
            b[j]++;
        }
    }
    For(i, 0, n - 1) {
        int j = 0;
        if (i == 0) ++j;
        for (; j < s[i] - '0'; j++) {
            b[j]--;
            ans += mul(n - i - 1, mask);
            b[j]++;
        }
        b[s[i] - '0']--;
    }
    ans += mul(0, mask);
    return ans;
}
int main() {
    For(i, 0, 18) ck[i][0] = 1;
    For(i, 1, 18) {
        For(j, 1, i) {
            ck[i][j] = ck[i - 1][j - 1] + ck[i - 1][j];
        }
    }
    For(i, 1, 18) {
        p[i][0] = 1;
        For(j, 1, 18) {
            p[i][j] = p[i][j - 1] * i;
        }
    }
    int t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        ll ans = 0;
        string s1 = to_string(r), s2 = to_string(l - 1);
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        For(i, 1, 1023) {
            if (__builtin_popcount(i) % 2 == 1) {
                ans += solve(s1, i) - solve(s2, i);
            } else {
                ans -= solve(s1, i) - solve(s2, i);
            }
        }
        cout << (r - l + 1) - ans << endl;
    }
    return 0;
}
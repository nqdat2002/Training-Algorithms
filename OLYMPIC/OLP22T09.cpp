#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int maxn = 2e6 + 5;
const int N = 5e5 + 5;
ll n, m;
ll a[N], pos[N], f[maxn];

void update(ll i, ll value) {
	for (; i < maxn; i += i & -i)
		f[i] += value;
}

ll get(ll i) {
	ll ans = 0;
	for (; i; i -= i & -i)
		ans += f[i];
	return ans;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			pos[a[i]] = i + m;
			update(pos[a[i]], 1);
		}
		ll l = m, r = n + m + 1, ans = 0;
		while (m--) {
			ll x;
			char type;
			cin >> x >> type;
			ll left = get(pos[x] - 1);
			ll right = n - left - 1;

			ans += min(left, right);
			if (type == 'l') {
				update(pos[x], -1);
				pos[x] = l--;
				update(pos[x], 1);
			}
			else {
				update(pos[x], -1);
				pos[x] = r++;
				update(pos[x], 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
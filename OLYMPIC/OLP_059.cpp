#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pr;
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
const ll N = 1e5 + 5;
const ll p = mod;

ll n, ans;
string s;
ll Pow[N], hashLeft[N], hashRight[N];

void setPow() {
	Pow[0] = 1;
	for (ll i = 1; i <= N; i++) Pow[i] = (Pow[i - 1] * 26) % p;
}
void setLeft() {
	for (ll i = 1; i <= n; i++) hashLeft[i] = (hashLeft[i - 1] * 26 + s[i] - 'a') % p;
}
void setRight() {
	for (ll i = n; i >= 1; i--) hashRight[i] = (hashRight[i + 1] * 26 + s[i] - 'a') % p;
}
ll getLeft(ll i, ll j) {
	return (hashLeft[j] - hashLeft[i - 1] * Pow[j - i + 1] + p * p) % p;
}
ll getRight(ll i, ll j) {
	return (hashRight[i] - hashRight[j + 1] * Pow[j - i + 1] + p * p) % p;
}
bool check(ll i, ll j) {
	return (getLeft(i, j) == getRight(i, j));
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	setPow();
	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		s = " " + s;
		setLeft();
		setRight();
		ans = 0;
		for (ll i = 1; i <= n; i++) {
			// le
			ll l = 0, r = min(i, n - i);
			while (l <= r) {
				ll m = (l + r) >> 1;
				if (check(i - m + 1, i + m)) {
					ans = max(ans, m * 2);
					l = m + 1;
				}
				else r = m - 1;
			}
			// chan
			l = 0, r = min(i - 1, n - i);
			while (l <= r) {
				ll m = (l + r) >> 1;
				if (check(i - m, i + m)) {
					ans = max(ans, m * 2 + 1);
					l = m + 1;
				}
				else r = m - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
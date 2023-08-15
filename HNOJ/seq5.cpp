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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int get(int i) {
	if (i % 3 == 0 || i % 3 == 1)
		return 1;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k; cin >> n >> k;
	ll a[n + 1];
	ll f[3 * k + 1][n + 1];
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = 0; i <= n; ++i) f[0][i] = 0;

	for (int i = 1; i <= 3 * k; ++i) {
		int x = get(i);
		f[i][i] = x * a[i] + f[i - 1][i - 1];
		for (int j = i + 1; j <= n; ++j)
			f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + a[j] * x);
	}
	cout << f[3 * k][n] << endl;
	return 0;
}

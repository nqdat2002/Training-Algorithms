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

int get1(int i) {
	if (i % 3 == 0 || i % 3 == 1)
		return 1;
	return -1;
}

int get2(int i) {
	if (i % 3 == 0) return -1;
	return 1;
}

int get3(int i) {
	if (i % 3 == 1) return -1;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k; cin >> n >> k;
	ll a[n + 1];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	ll f1[3 * k + 1][n + 1], f2[3 * k + 1][n + 1], f3[3 * k + 1][n + 1], res = -oo;

	for (int i = 0; i <= n; ++i) f1[0][i] = 0, f2[0][i] = 0, f3[0][i] = 0;

	for (int i = 1; i <= 3 * k; ++i) {
		int x = get1(i);
		f1[i][i] = x * a[i] + f1[i - 1][i - 1];
		for (int j = i + 1; j <= n; ++j)
			f1[i][j] = max(f1[i][j - 1], f1[i - 1][j - 1] + a[j] * x);
	}
	res = max(res, f1[3 * k][n]);

	for (int i = 1; i <= 3 * k; ++i) {
		int x = get2(i);
		f2[i][i] = x * a[i] + f2[i - 1][i - 1];
		for (int j = i + 1; j <= n; ++j)
			f2[i][j] = max(f2[i][j - 1], f2[i - 1][j - 1] + a[j] * x);
	}
	res = max(res, f2[3 * k][n]);
	
	for (int i = 1; i <= 3 * k; ++i) {
		int x = get3(i);
		f3[i][i] = x * a[i] + f3[i - 1][i - 1];
		for (int j = i + 1; j <= n; ++j)
			f3[i][j] = max(f3[i][j - 1], f3[i - 1][j - 1] + a[j] * x);
	}
	res = max(res, f3[3 * k][n]);

	cout << res << endl;
	return 0;
}

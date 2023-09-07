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

struct matrix {
	ll x[11][11];
} a, b;

matrix operator * (matrix a, matrix b) {
	matrix c;
	for (int i = 0; i < 11; i ++) {
		for (int j = 0; j < 11; j ++) {
			c.x[i][j] = 0;
			for (int k = 0; k < 11; k ++) {
				c.x[i][j] = (c.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
				c.x[i][j] %= mod;
			}
		}
	}
	return c;
}

matrix Power(matrix a, ll k) {
	if (k == 1)
		return a;
	matrix t = Power(a, k / 2);
	if (k & 1)
		return t * t * a;
	return t * t;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while (t--) {
		ll n, x; cin >> n >> x;
		ll l = n - x, r = 2 * x;
		ll res = 0;
		matrix trans_fibo;
		a.x[0][0] = a.x[0][1] = a.x[1][0] = 1;
		a.x[1][1] = 0;


		if (l == 0) {
			trans_fibo = Power(trans_fibo, r + 1);
			res = trans_fibo.x[0][0];
		}
		else {
			matrix trans, first_bad, first_good;
			trans.x[0][0] = trans.x[0][1] = trans.x[0][2] = 1;
			trans.x[1][0] = trans.x[1][2] = 1;
			trans.x[1][1] = 0;
			trans.x[2][0] = trans.x[2][1] = 1;
			trans.x[2][2] = 0;

			first_bad.x[0][0] = first_bad.x[1][0] = 0;
			first_bad.x[2][0] = 1;
			first_good.x[0][0] = 1;
			first_good.x[1][0] = first_good.x[2][0] = 0;

			matrix res_bad = Power(trans, l - 1);
			res_bad = res_bad * first_bad;

			matrix res_good = Power(trans, l - 1);
			res_good = res_good * first_good;

			if (r == 0) {
				res += res_good.x[0][0] + res_good.x[1][0] + res_good.x[2][0];
				res += res_bad.x[0][0] + res_bad.x[2][0];
			}
			else {
				matrix f1 = Power(trans_fibo, r + 1);
				ll yy = f1.x[0][0];
				res += (res_good.x[0][0] + res_good.x[2][0]) * yy;
                res += res_good.x[1][0] * yy;

                matrix f2 = Power(trans_fibo, r);
                ll zz = f2.x[0][0];
                res += (res_bad.x[0][0] + res_bad.x[2][0]) * zz;
                matrix f3 = Power(trans_fibo, r - 1);
                ll tt = f3.x[0][0];
                res += res_bad.x[1][0] * tt;
			}
			if (res >= 2 * n) res -= 2 * n;
			if (res < 0) res += mod;
			cout << res - 1 << endl;
		}
		cout << endl;
	}
	return 0;
}
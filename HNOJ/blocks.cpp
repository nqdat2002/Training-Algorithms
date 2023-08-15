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
struct matrix {
	ll x[4][4];
};
ll n, k;
matrix operator * (matrix a, matrix b) {
	matrix c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c.x[i][j] = 0;
			for (int h = 0; h < 2; h++) {
				c.x[i][j] = (c.x[i][j] + (a.x[i][h] * b.x[h][j]));
				c.x[i][j] %= k;
			}
		}
	}
	return c;
}

matrix Power(matrix a, ll pp) {
	if (pp == 1)
		return a;
	matrix t = Power(a, pp / 2);
	if (pp & 1)
		return t * t * a;
	return t * t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	if (n == 2) cout << 1 % k;
	else if (n == 3) cout << 2 % k;
	else {
		matrix a;
		a.x[0][0] = 3;
		a.x[0][1] = -1;
		a.x[1][0] = 1;
		a.x[1][1] = 0;
		matrix res = Power(a, n - 1);

		matrix b;
		b.x[0][0] = 1;
		b.x[0][1] = 0;
		b.x[1][0] = 2;
		b.x[1][1] = 0;
		res = res * b;
		while(res.x[0][0] < 0) res.x[0][0] += k;
		cout << res.x[0][0] << endl;
	}
	return 0;
}
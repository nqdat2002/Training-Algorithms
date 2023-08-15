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

int n, k;
struct matrix {
	int row, col;
	vector <std::vector <ll> > data;
	matrix(int _row, int _col) {
		row = _row;
		col = _col;
		data.resize(row);
		for (int i = 0; i < row; i++) {
			data[i].resize(col, 0LL);
		}
	}
	matrix operator * (const matrix &other) {
		matrix ans(row, other.col);
		for (int i = 0; i < ans.row; i++) {
			for (int j = 0; j < ans.col; j++) {
				for (int k = 0; k < col; k++) {
					(ans.data[i][j] += (data[i][k] * other.data[k][j]) % mod) %= mod;
				}
			}
		}
		return ans;
	}
};

matrix pow(const matrix &M, int n) {
	if (n == 1)
		return M;
	matrix ans = pow(M, n / 2);
	ans = ans * ans;
	if (n & 1)
		ans = ans * M;
	return ans;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	matrix ret(1, k);
	ret.data[0][0] = 1;
	matrix base(k, k);
	for (int i = 0; i < k; i++) {
		int previ = (i - 1 + k) % k;
		base.data[previ][i] = 3LL;
		previ = (i - 2 % k + k) % k;
		base.data[previ][i] = 3LL;
		base.data[i][i] = 1LL;
	}
	// for(int i = 0; i < n; ++i){
	// 	for(int j = 0; j < k; ++j) 
	// 		cout << base.data[i][j] << " ";
	// 	cout << endl;
	// }
	base = pow(base, n);
	ret = ret * base;
	cout << (ret.data[0][0] - 1 + mod) % mod;
	return 0;
}
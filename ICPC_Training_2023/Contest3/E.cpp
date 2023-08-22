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

bool isOdd(const vector< vector<int> >& a) {
	int n = (int)a.size();
	vector< vector<int> > prefixSum(n + 1, vector<int> (n + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + a[i - 1][j - 1];

	for (int k = 2; k <= n; ++k) {
		int sum = 0;
		for (int i = 0; i <= n - k; ++i) {
			for (int j = 0; j <= n - k; ++j) {
				sum = (prefixSum[i + k][j + k] - prefixSum[i][j + k] - prefixSum[i + k][j] + prefixSum[i][j]);
				if (sum % 2 == 0)
					return false;
			}
		}

	}
	return true;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int N; cin >> N;
		vector<vector<int>> matrix(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> matrix[i][j];
			}
		}

		if (isOdd(matrix)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		cout << endl;
	}
	return 0;
}
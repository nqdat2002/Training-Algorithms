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

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t = 1;
	while (t--) {
		int n, c; 
		cin >> n >> c;
		int a[n - 1], b[n - 1];
		for (auto &x: a) cin >> x;
		for (auto &x: b) cin >> x;

		vector<vector<int>> dp(n, vector<int> (2, INT_MAX));
		dp[0][0] = 0;
		dp[0][1] = c;
		for (int i = 0; i < n - 1; ++i){
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a[i]);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a[i]);
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b[i]);
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + b[i] + c);
		}

		for (int i = 0; i < n; ++i) cout << min(dp[i][0], dp[i][1]) << " ";
		cout << endl;
	}
	return 0;
}
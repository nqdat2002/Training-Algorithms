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
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		string res = s;
		sort(res.begin(), res.end());
		if (!(k & 1)) {
			cout << res << endl;
			continue;
		}
		int dp[26][2];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i)
			dp[s[i] - 97][i % 2]++;
		res = "";
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < 26; ++i) {
				if (dp[i][j % 2]) {
					dp[i][j % 2] --;
					res += char(i + 97);
					break;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
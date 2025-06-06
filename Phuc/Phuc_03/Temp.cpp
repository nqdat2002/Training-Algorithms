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
		string s; cin >> s;
		stack<int> st;
		vector<int> dp(s.size(), 0);
		int res = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == '[') {
				st.push(i);
			} else {
				if (!st.empty()) {
					int j = st.top();
					if ((s[i] == ')' && s[j] == '(') || (s[i] == ']' && s[j] == '[')) {
						st.pop();
						dp[i] = i - j + 1;
						if (j > 0) dp[i] += dp[j - 1];
						int cnt = 0;
						for (int k = i - dp[i] + 1; k <= i; ++k) {
							if (s[k] == '[') cnt++;
						}
						res = max(res, cnt);
					} else {
						while (!st.empty()) st.pop();
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
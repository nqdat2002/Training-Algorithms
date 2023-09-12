/*
	author: datnq02
*/

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
		int n; cin >> n;
		string s; cin >> s;
		int i = 0, j = n - 1;
		int same1 = 0, same0 = 0, cnt = 0;
		while (i < j) {
			if (s[i] != s[j]) cnt++;
			else if (s[i] == s[j]) {
				if (s[i] == '0') same0 ++;
				else same1++;
			}
			i++;
			j--;
		}
		vector<int>v(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			if (cnt <= i) {
				int c = i - cnt;
				if (c > ((same0 + same1) << 1) + n % 2) continue;
				if (c & 1) {
					if ((n & 1))
						v[i] = 1;
					else continue;
				}
				else v[i] = 1;
			}
		}
		if (cnt == 0) v[0] = 1;
		for (auto x : v) cout << x;
		cout << endl;
	}
	return 0;
}
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
		string s;
		cin >> s;
		int n = s.length(), cnt = 0;
		bool all = (s[0] == 'B' || s[n - 1] == 'B');
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1] && s[i] == 'B') {all = true;}
		}
		vector<int> lens;
		int curr = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') {curr++;}
			else {
				if (curr != 0) {lens.push_back(curr);}
				curr = 0;
			}
		}
		if (curr != 0) {lens.push_back(curr);}
		sort(lens.begin(), lens.end());

		if (lens.empty()) {
			cout << 0 << '\n';
			continue;
		}

		int tot = 0;
		if (all) {tot += lens[0];}
		for (int i = 1; i < lens.size(); i++) {
			tot += lens[i];
		}
		cout << tot << '\n';
	}
	return 0;
}
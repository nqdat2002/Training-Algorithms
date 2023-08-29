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
		string s; cin >> s;
		int n = s.size();
		int freq[26];
		memset(freq, 0, sizeof(freq));
		for (int i = 0; i < n; i++)
			freq[(int) (s[i] - 'A')]++;

		int odd = -1;
		for (int i = 0; i < 26; i++) {
			if (freq[i] & 1) {
				if (odd != -1) {
					cout << "NO SOLUTION" << endl;
					return 0;
				} else {
					odd = i;
				}
			}
		}

		for (int i = 0; i < 26; i++)
			for (int j = 0; j < freq[i] / 2; j++)
				cout << char(i + 'A');
		if (odd != -1)
				cout << char(odd + 'A');
		for (int i = 25; i >= 0; i--)
			for (int j = 0; j < freq[i] / 2; j++)
				cout << char(i + 'A');
		cout << endl;
	}
	return 0;
}
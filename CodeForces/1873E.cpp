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

int Binary_Search(int a[], int n, int x) {
	return 0;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		int a[n];
		for (auto &x : a) cin >> x;
		ll low = 1, high = 10000000000, res = 10000000000, cnt = 0;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			cnt = 0;
			for (auto y : a) {
				cnt += (mid > y ? mid - y : 0);
			}
			if (cnt <= x) {
				res = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}
		cout << res << endl;
	}
	return 0;
}
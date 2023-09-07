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
const int maxN = 2e5 + 1;
int n, x, a;
pair<int, int> v[maxN];

int find(int val) {
	int l = 1, r = n;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (v[m].first == val) 
			return v[m].second;
		else if (v[m].first < val) l = m + 1;
		else r = m - 1;
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v + 1, v + n + 1);

	for (int i = 1; i <= n; i++) {
		int d = find(x - v[i].first);
		if (d != 0 && d != v[i].second) {
			cout << v[i].second << " " << d << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
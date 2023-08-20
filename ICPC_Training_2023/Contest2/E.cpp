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
#define pb push_bavs
#define ep emplace_bavs
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

	int n, q, a[1001], h[1001], t[1000001];
	cin >> n >> q;
	bool vs[1001];
	for (int i = 1; i < n; ++i) cin >> a[i];
	for (int i = 1; i <= q; ++i) cin >> t[i];
	for (int i = n; i > 1; --i) {
		int cnt = 0, j = n;
		while (cnt <= a[i - 1]){
			if (vs[j] == false) 
				++cnt;
			--j;
		}
		h[i] = j + 1; 
		vs[j + 1] = true;
	}
	int j = 1;
	while (vs[j] == true) ++j;
	h[1] = j;
	for (int i = 1; i <= q; ++i)
		cout << n - h[t[i]] + 1 << "\n";
	return 0;
}
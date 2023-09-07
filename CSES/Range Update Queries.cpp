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
 
const int N = 200005;
ll bit[N];
int n, q;
ll a[N + 1];
 
void update(int u, int v) {
	int id = u;
	while (id <= n) {
		bit[id] += v;
		id += (id & (-id));
	}
}
 
void updateRange(int l, int r, int v) {
	update(l, v);
	update(r + 1, -v);
}
 
ll get(int u) {
	int id = u;
	ll res = 0;
	while (id > 0) {
		res += bit[id];
		id -= (id & (-id));
	}
	return res;
}
 
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		updateRange(i, i, a[i]);
	}
	while (q--) {
		int type, u, v, k;
		cin >> type;
		if(type == 1){
			cin >> u >> v >> k;
			updateRange(u, v, k);
		}
		else {
			cin >> u;
			cout << get(u) << endl;
		}
	}
	return 0;
}
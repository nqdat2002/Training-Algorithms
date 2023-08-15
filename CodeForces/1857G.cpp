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

const int N = 200000, mod = 998244353;
int p[N + 1], sz[N + 1];
struct edge{
	int u, v, w;
	void read() {cin >> u >> v >> w;}
	bool operator<(edge x) {return w < x.w;}

} a[N + 1];
int leader(int v){
	if (p[v] == v)
		return v;
	return p[v] = leader(p[v]);
}

void unite(int u, int v){
	u = leader(u);
	v = leader(v);
	p[u] = v;
	sz[v] += sz[u];
}
long long binpow(long long a, long long n)
{
	if (n == 0)return 1;
	if (n % 2 == 0)
		return binpow(a * a % mod, n / 2);
	return a * binpow(a, n - 1) % mod;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, S; cin >> n >> S;
		for (int i = 1; i <= n; i++)p[i] = i, sz[i] = 1;
		for (int i = 0; i < n - 1; i++)a[i].read();
		sort(a, a + n - 1);
		long long ans = 1;
		for (int i = 0; i < n - 1; i++)
		{
			int sub_u = sz[leader(a[i].u)];
			int sub_v = sz[leader(a[i].v)];
			ans = ans * binpow(S - a[i].w + 1, 1ll * sub_u * sub_v - 1) % mod;
			unite(a[i].u, a[i].v);
		}
		cout << ans << "\n";
	}
	return 0;
}
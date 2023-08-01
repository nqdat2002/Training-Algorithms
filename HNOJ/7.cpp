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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

#define N 50005
int a[N], b[N], f[N], n, W;
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> W;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int m = 0;
	f[0] = 0;

	for (int i = 1; i <= n; i++) {
		int k = lower_bound(b + 1, b + m + 1, a[i]) - b;
		if(f[i] + a[i] <= W){
			f[i] = max(f[i], f[i - 1] + a[i]);
			m = max(m, k);
			b[k] = a[i];
		}
	}
	cout << m << endl;
	return 0;
}
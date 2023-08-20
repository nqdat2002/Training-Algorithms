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
const int N = 1e5 + 5;
int f[N], trace1[N], trace2[N], kt[N], vt[N], dT[N];
map<int, int> cnt;

void solve(int val, int type){
	int v = val * type;
    for (int i = sum; i >= v; --i)
        if (!f[i] && f[i - v]) {
            f[i] = 1;
            trace1[i] = val;
            trace2[i] = type;
        }
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
		int a[n + 1], b[n + 1];
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) cin >> b[i];

		memset(dT, 0, sizeof(dT));
		memset(kt, 0, sizeof(kt));

		for (int i = 1; i <= n; ++i) {
			dT[i] = abs(a[i] - b[i]);
			cnt[dT[i]] ++;
			if (dT[i] < 0) kt[i] = 1;
			s += abs(dT[i]);
		}
		cout << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 7;

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

const int nmax = 300005;
const ll oo = 1e18;

int n, a[nmax];
ll fl[nmax], fr[nmax];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();

	cin >> n;
	for (int i = 0; i < 3 * n; ++i) cin >> a[i];

	ll sum = 0;
	priority_queue<int, vector<int>, greater<int> > ql;
	for (int i = 0; i < 3 * n; ++i) {
		sum += a[i];
		ql.push(a[i]);
		if (ql.size() > n) {
			sum -= ql.top();
			ql.pop();
		}
		fl[i] = sum;
	}

	sum = 0;
	priority_queue<int> qr;
	for (int i = 3 * n - 1; i >= 0; --i) {
		sum += a[i];
		qr.push(a[i]);
		if (qr.size() > n) {
			sum -= qr.top();
			qr.pop();
		}
		fr[i] = sum;
	}

	ll res = -oo;
	for (int i = n - 1; i < 2 * n; ++i)
		res = max(res, fl[i] - fr[i + 1]);
	cout << res << endl;
	return 0;
}

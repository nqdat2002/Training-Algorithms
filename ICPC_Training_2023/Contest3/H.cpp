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

	ll n, k; cin >> n >> k;
	ll a[n];
	for (auto &x : a) cin >> x;
	sort(a, a + n);
	ll sum = 0, res = 0;
	ll start = 0, pre = n - 1;
	for (ll end = 0; end < n; ++ end) {
		sum += a[end];
		while ((ll)(end - start + 1) * a[end] - sum > k) {
			sum -= a[start];
			start++;
		}
		if (res < end - start + 1){
			res = end - start + 1;
			pre = end;
		}
	}

	cout << a[pre] << " " << res << endl;
	return 0;
}
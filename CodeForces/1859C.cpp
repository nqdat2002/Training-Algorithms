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
int a[251], n;
void next() {
	int j = n - 1;
	while (j > 0 && a[j] > a[j + 1])
		j--;
	if (j > 0) {
		int k = n;
		while (a[j] > a[k]) {
			k --;
		}
		swap(a[j], a[k]);
		int r = j + 1;
		int s = n;
		while (r <= s) {
			swap(a[r], a[s]);
			r ++;
			s --;
		}
	}
	else {
		for (int j = 1; j <= n; j ++)
			a[j] = j;
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		cin >> n;
		// ll cost = LONG_LONG_MIN;
		// for (int i = 1; i <= n; ++i) a[i] = i;
		// while (1) {
		// 	ll sum = 0, fmax = 0;
		// 	for (int i = 1; i <= n; ++i) sum += a[i] * i, fmax = max(fmax, (ll)(a[i] * i));
		// 	if (sum - fmax > cost) cost = max(cost, sum - fmax);
		// 	else if (sum - fmax < cost) {
		// 		cout << cost << endl;
		// 		break;
		// 	}
		// 	next();
		// }
		// cout << cost << endl;
		ll cost = 0;
		if(n == 2){
			cout << 2 << endl;
			continue;
		}
		for (int  i = 1; i <= n; ++i) {
			ll sumJ = 0, fmax = 0;
			for (int j = 1; j <= i; ++j){
				sumJ += j * j;
				fmax = max((ll)j * j, fmax);
			}
			for(int j = i + 1; j <= n; ++j){
				ll x = (n + i - j + 1) * j;
				sumJ += x;
				fmax = max(fmax, x);
			}
			cost = max(cost, sumJ - fmax);
		}
		cout << cost << endl;
	}
	return 0;
}
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

bool cmp(pair<ll, int> a, pair<ll, int> b) {
	return a.first > b.first;
}

void test() {
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> a(n + 1);
	a.push_back(0);
	for (int i = 1; i <= n; ++i) cin >> a[i], sumall += a[i];
	vector<pair<ll, int> > v(n + 1);
	v[0].first = v[0].second = 0;
	for (int i = 1; i <= n; ++i) {
		v[i].first = a[i];
		v[i].second = i;
	}
	sort(v.begin(), v.end(), cmp);
	for (auto x : v) {
		cout << x.first << " " << x.second << endl;
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> a(n + 1);
	a.push_back(0);
	vector<vector<int> > v;
	ll sumall = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i], sumall += a[i];
	for (int i = 1; i < n; ++i) {
		ll sum = a[i];
		vector<int> res;
		res.push_back(i);
		bool ok = false;
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] + sum <= r) {
				res.push_back(j);
				sum += a[j];
				if (sum >= l) {
					cout << res.size() << endl;
					for (int h = 0; h < res.size(); ++h) {
						cout << res[h] << " ";
					}
					ok = true;
					break;
				}
			}
		}
		if(ok) break;
	}

	return 0;
}
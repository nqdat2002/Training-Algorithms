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

void FileIO(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	ll t = __gcd(a.second, b.second);
	t = (a.second * b.second) / t;
	return a.first * (t / a.second) >= b.first * (t / b.second);
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n; cin >> n;
	ll a[n];
	for (auto &x : a) cin >> x;
	multiset<ll> ms;
	vector<pair<pair<ll, ll>, ll> > v;
	pair<ll, ll> p = make_pair(0, 1);
	ll sum = a[n - 1];
	for (ll i = n - 2; i > 0; --i) {
		sum += a[i];
		ms.insert(a[i]);
		pair<ll, ll> tmp;
		tmp.first = (sum - *ms.begin());
		tmp.second = (n - i - 1);
		ll t = __gcd(tmp.first, tmp.second);
		tmp.first /= t;
		tmp.second /= t;
		if (cmp(tmp, p)) {
			v.push_back({tmp, i});
			p = tmp;
		}
	}
	ll l = v.size() - 1;
	while (l >= 0 && cmp(v[l].first, p)) {
		cout << v[l].second << " ";
		l --;
	}
	return 0;
}
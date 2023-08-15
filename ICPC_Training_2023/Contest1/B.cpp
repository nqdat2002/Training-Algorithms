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
struct cmp {
	bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
		if (a.second != b.second)
			return a.second < b.second;
		return a.first < b.first;
	}
};
ll count(ll x) {
	ll cnt2 = 0, cnt5 = 0;
	while (x % 2 == 0 && x) {
		x /= 2;
		cnt2 += 1;
	}
	while (x % 5 == 0 && x) {
		x /= 5;
		cnt5 += 1;
	}
	ll res = 0;
	while (cnt2 > 0 && cnt5 > 0) {
		res ++;
		cnt2 -= 1;
		cnt5 -= 1;
	}
	return res;
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll a[n];
		for (auto &x : a) cin >> x;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll >>, cmp> q;
		for (auto x : a) q.push({x, count(x)});
		while (q.size()) {
			if (q.top().second) {
				q.pop();
				cnt += q.top().second;
				k--;
			}
		}
		while(k > 0){
			
		}
	}
	return 0;
}
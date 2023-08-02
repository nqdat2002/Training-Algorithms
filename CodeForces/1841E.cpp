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

struct seg {
	int l, r;
};

bool operator <(const seg &a, const seg &b) {
	return a.l < b.l;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		forn(i, n) scanf("%d", &a[i]);
		long long m;
		scanf("%lld", &m);
		map<seg, int> used;
		used[ {0, n}] = n;
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&a](int x, int y) {
			return a[x] > a[y];
		});
		long long ans = 0;
		int j = 0;
		vector<long long> cnt(n + 1);
		for (int i = n; i >= 0; --i) {
			while (j < n && a[ord[j]] >= i) {
				auto it = used.upper_bound({ord[j], -1});
				--it;
				auto tmp = it->first;
				cnt[tmp.r - tmp.l] += it->second - i;
				used.erase(it);
				if (tmp.l != ord[j])
					used[ {tmp.l, ord[j]}] = i;
				if (tmp.r != ord[j] + 1)
					used[ {ord[j] + 1, tmp.r}] = i;
				++j;
			}
		}
		for (int i = n; i > 0; --i) {
			long long t = min(cnt[i], m / i);
			ans += t * 1ll * (i - 1);
			m -= t * 1ll * i;
			if (t != cnt[i] && m > 0) {
				ans += m - 1;
				m = 0;
			}
		}
		printf("%lld\n", ans);
		cout << endl;
	}
	return 0;
}
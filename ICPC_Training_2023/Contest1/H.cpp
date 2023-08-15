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

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		ll n, k; cin >> n >> k;
		priority_queue<ll, vector<ll>, greater<ll> > q;
		ll a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			q.push(a[i]);
		}

		ll sum1 = 0;
		while (q.size() > 1) {
			ll sum = 0;
			ll max = LONG_LONG_MIN, min = LONG_LONG_MAX;
			if (q.size() < k) {
				while (q.size()) {
					if (q.top() > max) max = q.top();
					if (q.top() < min) min = q.top();
					sum += q.top();
					q.pop();
				}
			}

			else {
				ll cnt = k;
				while (cnt--) {
					if (q.top() > max) max = q.top();
					if (q.top() < min) min = q.top();
					sum += q.top();
					q.pop();
				}
			}
			sum1 += (max - min);
			q.push(sum);
		}
		cout << q.top() << endl << sum1 << endl;
	}
	return 0;
}
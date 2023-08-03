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

	int t; cin >> t;
	while (t--) {
		int n, m, h;
		cin >> n >> m >> h;
		pair<int, long long> rud;
		int ans = 1;
		
		for (int i = 0; i < n; i++) {
			vector<int> cur(m);
			for (int j = 0; j < m; j++) {
				cin >> cur[j];
			}
			sort(cur.begin(), cur.end());
			int task_cnt = 0;
			long long penalty = 0, sum = 0;
			for (int j = 0; j < m; j++) {
				if (sum + cur[j] > h) break;
				sum += cur[j];
				penalty += sum;
				task_cnt++;
			}
			if (i) {
				if (make_pair(-task_cnt, penalty) < rud) ans++;
			} else rud = { -task_cnt, penalty};
		}
		cout << ans << '\n';
	}
	return 0;
}
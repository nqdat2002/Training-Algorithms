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

/* */
template <class T>
bool minimize(T &a, const T &b) {
	if (a > b) {a = b; return 1;}
	return 0;
}

template <class T>
bool maximize(T &a, const T &b) {
	if (a < b) {a = b; return 1;}
	return 0;
}

const int N = 200 + 7, M = 25;

int n, k, pw2[N], pw5[N];
int _dp[N][N * M];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll v; cin >> v;
		while (v % 2 == 0) v /= 2, pw2[i]++;
		while (v % 5 == 0) v /= 5, pw5[i]++;
	}
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= n * M; j++) {
			_dp[i][j] = -oo;
		}
	}
	_dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = k; j > 0; j--) {
			for (int v = pw5[i]; v <= i * M; v++) {
				maximize(_dp[j][v], _dp[j - 1][v - pw5[i]] + pw2[i]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n * M; i++) {
		maximize(ans, min(i, _dp[k][i]));
	}
	cout << ans << "\n";
	return 0;
}
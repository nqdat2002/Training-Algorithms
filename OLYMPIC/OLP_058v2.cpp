#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
const ll p = mod;
string T, P;
const ll N = 1000111;

ll Pow[N], Hash[N];
ll n, m;
void setPow() {
	Pow[0] = 1;
	for (ll i = 1; i <= m; i++) Pow[i] = (Pow[i - 1] * 26) % p;
}

ll getHashP() {
	ll HashP = 0;
	for (ll i = 1; i <= m; ++i) HashP += (P[i] - 'a') * Pow[i] % p;
	return HashP % p;
}
ll getHashLR(ll L, ll R) {
	ll res = 0;
	for (ll i = L; i <= R; ++i) res += (T[i] - 'a') * Pow[i] % p;
	return res % p;
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		cin >> T >> P;
		n = T.size(), m = P.size();
		T = " " + T;  P = " " + P;
		setPow();
		for (ll i = 1; i <= n - m + 1; ++i) {
			if (getHashLR(i, i + m - 1) == (getHashP() * (Pow[i - 1] % p)) % p) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
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
	for (int i = 1; i <= m; i++) Pow[i] = (Pow[i - 1] * 26) % p;
}
void setHash() {
	for (int i = 1; i <= m; i++)
		Hash[i] = (Hash[i - 1] * 26 + T[i] - 'a') % p;
}
int getHash(int i, int j) {
	return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + p * p) % p;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		cin >> T >> P;
		m = T.size(), n = P.size();
		T = " " + T;  P = " " + P;
		setPow();
		setHash();
		ll hash_p = 0;
		for (ll i = 1; i <= n; i++)
			hash_p = (hash_p * 26 + P[i] - 'a') % p;
		for (ll i = 1; i <= m - n + 1; i++) {
			if (hash_p == getHash(i, i + n - 1))
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
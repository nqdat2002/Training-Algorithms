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
const int N = 1e5 + 5;
bool isPrime[N + 1];

void sieve() {
	for (int i = 0; i <= N; ++i) {
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i <= N; ++i) {
		if (isPrime[i] == true) {
			for (int j = i * i; j <= N; j += i)
				isPrime[j] = false;
		}
	}
}

vector<int> factor(int x) {
	vector<int> res;
	int fact = 1;
	while (fact < x) {
		res.push_back(fact);
		fact <<= 1;
	}
	return res;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		vector<int> v = factor(x);
		int l = v.back(), r = x - v.back();
		bool deg = 0;
		if (r & 1) r -= 1, deg = 1;
		for (int i = 32; i >= 0; i--) {
			if (r & (1 << i)) {
				l += pow(2, i);
				v.push_back(l);
			}
		}
		if (deg) {
			cout << v.size() + 1 << endl;
			cout << x << " ";
		}
		else cout << v.size() << endl;
		reverse(v.begin(), v.end());
		for (auto x : v) cout << x << " ";
		cout << endl;
	}
	return 0;
}
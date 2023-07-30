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
set<long long> nums;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (long long k = 2; k <= 1000; ++k) {
		long long val = 1 + k;
		long long p = k * k;
		for (int cnt = 2; cnt <= 20; ++cnt) {
			val += p;
			if (val > 1e6) break;
			nums.insert(val);
			p *= k;
		}
	}

	int _ = 0, __ = 1;
	cin >> __;

	for (int _ = 0; _ < __; ++_) {
		long long n;
		cin >> n;


		if (nums.count(n)) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;
}
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
bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first < b.first) return false;
	else if(a.first > b.first) 
		return true;
	return a.second < b.second;
};

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> res;
		for (int i = 0; i < n; ++i){
			a[i] %= k;
			if (a[i] == 0){
				res.push_back(i + 1);
			}
		}
		vector<pair<int, int> > v(n);
		for (int i = 0; i < n; i++) {
			v[i].first = a[i];
			v[i].second = i + 1;
		}
		sort(v.begin(), v.end(), cmp);
		for (auto x : v) {
			if (x.first != 0)
				res.push_back(x.second);
		}
		for (auto x : res) cout << x << " ";
		cout << endl;
	}
	return 0;
}
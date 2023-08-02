#include<bits/stdc++.h>

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

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i].first >> s[i].second;

		vector<pair<int, int>> pairs;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (max(s[i].first, s[j].first) <= min(s[i].second, s[j].second))
					pairs.push_back({min(s[i].first, s[j].first), max(s[i].second, s[j].second)});

		int cnt_pairs = 0;
		sort(pairs.begin(), pairs.end(), cmp);
		int last_pos = -1;
		for (auto x : pairs)
			if (x.first > last_pos){
				cnt_pairs++;
				last_pos = x.second;
			}

		cout << n - cnt_pairs * 2 << endl;
	}
	return 0;
}
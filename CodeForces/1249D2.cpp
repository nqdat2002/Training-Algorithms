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

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> segs(n);
	vector<int> cnt(N);
	vector<vector<int>> ev(N);
	for (int i = 0; i < n; ++i) {
		cin >> segs[i].first >> segs[i].second;
		++cnt[segs[i].first];
		--cnt[segs[i].second + 1];
		ev[segs[i].first].push_back(i + 1);
		ev[segs[i].second + 1].push_back(-i - 1);
	}

	for (int i = 1; i < N; ++i) cnt[i] += cnt[i - 1];


	vector<int> ans(n), sub(N);
	set<pair<int, int>> curSegs;
	int curSub = 0;
	for (int i = 0; i < N; ++i) {
		curSub += sub[i];
		for (auto it : ev[i]) {
			if (it > 0) {
				curSegs.insert(make_pair(segs[it - 1].second, it - 1));
			} else {
				auto iter = curSegs.find(make_pair(segs[-it - 1].second, -it - 1));
				if (iter != curSegs.end()) curSegs.erase(iter);
			}
		}
		while (cnt[i] - curSub > k) {
			assert(!curSegs.empty());
			int pos = curSegs.rbegin()->second;
			curSegs.erase(prev(curSegs.end()));
			++curSub;
			--sub[segs[pos].second + 1];
			ans[pos] = 1;
		}
	}

	cout << accumulate(ans.begin(), ans.end(), 0) << endl;
	for (int i = 0; i < n; ++i) {
		if (ans[i]) cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}
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


int medianRowwiseSortedMatrix(vector<vector<int>> A, int N, int M) {
	int min = INT_MAX;
	int max = INT_MIN;
	int desired_count = (1 + (N * M) / 2);
	for (int i = 0; i < N; i++) {
		if (A[i][0] < min)
			min = A[i][0];
		if (A[i][M - 1] > max)
			max = A[i][M - 1];
	}
	int counter = 0;
	while (min < max) {
		counter = 0;
		int mid = (max + min) / 2;
		for (int i = 0; i < N; i++) {
			counter += upper_bound(A[i].begin(), A[i].end(), mid) -  A[i].begin();
		}
		if (counter < desired_count)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t = 1;
	while (t--) {
		int n, m; cin >> n >> m;
		int h, w; cin >> h >> w;
		int a[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> a[i][j];
		}
		int res = INT_MAX;
		for (int i = 0; i <= n - h; ++i) {
			for (int j = 0; j <= m - w; ++j) {
				vector<vector<int> > v;
				for (int k = i; k < i + h; ++k) {
					vector<int>v2;
					for (int h = j; h < j + w; ++h) {
						v2.push_back(a[k][h]);
					}
					v.push_back(v2);
				}
				res = min(res, medianRowwiseSortedMatrix(v, h, w));
			}
		}
		cout << res << endl;
	}
	return 0;
}
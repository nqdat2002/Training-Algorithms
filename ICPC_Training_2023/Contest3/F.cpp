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
const pair<int, int> HM[] = {{ -2, -1}, {2, -1}, { -1, -2}, { -1, 2}, {2, 1}, { -2, 1}, {1, 2}, {1, -2}};

struct Point {
	int x, y;
};


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	vector<int> ax(n + 1), ay(n + 1);
	map<int, vector<int> > bx, by;
	for (int i = 1; i <= n; ++i){
		cin >> ax[i] >> ay[i];
		bx[ax[i]].push_back(i);
		by[ay[i]].push_back(i);
	}
	int counter = 0;
    for (auto e: bx){
        ++counter;
        for (int p: e.second)
            ax[p] = counter;
    }
	for(int i = 1; i <= n; ++i){
		cout << a[i].x << " " << a[i].y << endl;
	}
	return 0;
}
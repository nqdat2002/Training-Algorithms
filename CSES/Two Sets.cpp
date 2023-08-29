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
	int t = 1;
	while (t--) {
		int N; cin >> N;
		if (N % 4 == 1 || N % 4 == 2)    cout << "NO" << endl;
		else if (N % 4 == 3) {
			cout << "YES" << endl;
			cout << N / 2 << endl;
			for (int i = 2; i <= N / 2; i += 2)
				cout << i << " " << N - i << " ";
			cout << N << "\n" << N / 2 + 1 << endl;
			for (int i = 1; i <= N / 2; i += 2)
				cout << i << " " << N - i << " ";
		} else {
			cout << "YES" << endl;
			cout << N / 2 << endl;
			for (int i = 2; i <= N / 2; i += 2)
				cout << i << " " << N - i + 1 << " ";
			cout << endl;
			cout << N / 2 << endl;
			for (int i = 1; i <= N / 2; i += 2)
				cout << i << " " << N - i + 1 << " ";
		}
	}
	return 0;
}
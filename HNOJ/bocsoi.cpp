#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
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

ll f[31][31][31][31][31];
ll f1[31][31][31];

const int mod = 111539786;

void print(int a[], int n) {
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}

ll calcSubTask1(int a1, int a2, int a3) {
	if (f1[a1][a2][a3] > -1)
		return f1[a1][a2][a3];
	ll res = 0;
	if (a1 % 2 == 1 && a2 % 2 == 1) {
		res = res + calcSubTask1(a1 - 1, a2 - 1, a3);
	}
	if (a2 % 2 == 1 && a3 % 2 == 1) {
		res = res + calcSubTask1(a1, a2 - 1, a3 - 1);
	}
	if (a1 % 2 == 1 && a3 % 2 == 1) {
		res = res + calcSubTask1(a1 - 1, a2, a3 - 1);
	}
	if (a1 > 0 && a2 > 0) {
		res = res + calcSubTask1(a1 / 2, a2 / 2, a3);
	}
	if (a3 > 0 && a2 > 0) {
		res = res + calcSubTask1(a1, a2 / 2, a3 / 2);
	}
	if (a1 > 0 && a3 > 0) {
		res = res + calcSubTask1(a1 / 2, a2, a3 / 2);
	}
	f1[a1][a2][a3] = res;
	return f1[a1][a2][a3];
}

void Subtask1() {
	int n; cin >> n;
	int a1, a2, a3; cin >> a1 >> a2 >> a3;
	memset(f1, -1, sizeof(f1));
	f1[0][0][0] = 1;
	cout << calcSubTask1(a1, a2, a3) << endl;
}


ll calcSubTask2(int a[], int n) {
	if (f[a[0]][a[1]][a[2]][a[3]][a[4]] > -1) {
		return f[a[0]][a[1]][a[2]][a[3]][a[4]];
	}
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		if (a[i] % 2 == 1 && a[j] % 2 == 1) {
			a[i]--;
			a[j]--;
			res = res + calcSubTask2(a, n);
			a[i]++;
			a[j]++;
		}
	}

	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		if (a[i] > 0 && a[j] > 0) {
			int ai = a[i], aj = a[j];
			if (ai % 2 == 1 && aj % 2 == 1) {
				a[i] = (a[i] - 1) / 2;
				a[j] = (a[j] - 1) / 2;
				res = res + calcSubTask2(a, n);
				a[i] = a[i] * 2 + 1;
				a[j] = a[j] * 2 + 1;
			}
			if (ai % 2 == 1 && aj % 2 == 0) {
				a[i] = (a[i] - 1) / 2;
				a[j] /= 2;
				res = res + calcSubTask2(a, n);
				a[i] = a[i] * 2 + 1;
				a[j] = a[j] * 2;
			}
			if (ai % 2 == 0 && aj % 2 == 1) {
				a[i] /= 2;
				a[j] = (a[j] - 1) / 2;
				res = res + calcSubTask2(a, n);
				a[i] = a[i] * 2;
				a[j] = a[j] * 2 + 1;
			}
			if (ai % 2 == 0 && aj % 2 == 0) {
				a[i] /= 2;
				a[j] /= 2;
				res = res + calcSubTask2(a, n);
				a[i] = a[i] * 2;
				a[j] = a[j] * 2;
			}
		}
	}
	return 	f[a[0]][a[1]][a[2]][a[3]][a[4]] = res;
}

void Subtask2() {
	int n; cin >> n;
	int a[5];
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (n == 3) a[4] = a[3] = 0;
	if (n == 4) a[4] = 0;
	memset(f, -1, sizeof(f));
	f[0][0][0][0][0] = 1;
	cout << calcSubTask2(a, n) << endl;
}

int id[30001];

int getId(int x) {
	if (x == 0) return 0;
	if (id[x] > -1) return id[x];
	if (x % 2 == 1)
		return id[x] = getId(x - 1) + 1;
	return id[x] = getId(x / 2) + 1;
}

ll calcSubTask3(int a[], int n) {
	int ia[5];
	for (int i = 0; i < 5; ++i) ia[i] = getId(a[i]);
	// for (int i = 0; i < 5; ++i) cout << ia[i] << " " << a[i] << endl;
	if (f[ia[0]][ia[1]][ia[2]][ia[3]][ia[4]] > -1) {
		return f[ia[0]][ia[1]][ia[2]][ia[3]][ia[4]] % mod;
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		if (a[i] % 2 == 1 && a[j] % 2 == 1) {
			a[i]--;
			a[j]--;
			res = res + calcSubTask3(a, n) % mod;
			a[i]++;
			a[j]++;
		}
	}

	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		if (a[i] > 0 && a[j] > 0) {
			int ai = a[i], aj = a[j];
			if (ai % 2 == 1 && aj % 2 == 1) {
				a[i] = (a[i] - 1) / 2;
				a[j] = (a[j] - 1) / 2;
				res = res + calcSubTask3(a, n) % mod;
				a[i] = a[i] * 2 + 1;
				a[j] = a[j] * 2 + 1;
			}
			if (ai % 2 == 1 && aj % 2 == 0) {
				a[i] = (a[i] - 1) / 2;
				a[j] /= 2;
				res = res + calcSubTask3(a, n) % mod;
				a[i] = a[i] * 2 + 1;
				a[j] = a[j] * 2;
			}
			if (ai % 2 == 0 && aj % 2 == 1) {
				a[i] /= 2;
				a[j] = (a[j] - 1) / 2;
				res = res + calcSubTask3(a, n) % mod;
				a[i] = a[i] * 2;
				a[j] = a[j] * 2 + 1;
			}
			if (ai % 2 == 0 && aj % 2 == 0) {
				a[i] /= 2;
				a[j] /= 2;
				res = res + calcSubTask3(a, n) % mod;
				a[i] = a[i] * 2;
				a[j] = a[j] * 2;
			}
		}
	}
	return 	f[ia[0]][ia[1]][ia[2]][ia[3]][ia[4]] = res % mod;
}

void Subtask3() {
	int n; cin >> n;
	int a[5];
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (n == 3) a[4] = a[3] = 0;
	if (n == 4) a[4] = 0;
	memset(f, -1, sizeof(f));
	memset(id, -1, sizeof(id));
	f[0][0][0][0][0] = 1;
	id[0] = 0;
	cout << calcSubTask3(a, n) % mod << endl;
}

void Test() {
	int n; cin >> n;
	int a[5];
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (n == 3) a[4] = a[3] = 0;
	if (n == 4) a[4] = 0;
	memset(id, -1, sizeof(id));
	int ia[5];
	for (int i = 0; i < 5; ++i) ia[i] = getId(a[i]);
	for (int i = 0; i < 5; ++i) cout << ia[i] << " " << a[i] << endl;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		// Subtask1();
		// Subtask2();
		Subtask3();
		// Test();
	}
	return 0;
}
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

bool check(string s) {
	stack<char> st;
	bool ok = true;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == '(') st.push(s[i]);
		else if (s[i] == ')') {
			if (st.empty()) ok = false;
			else if (st.top() == '(') st.pop();
		}
	}
	if (st.size()) ok = false;
	return ok == true;
}

string change(string s) {
	int n = s.length(), cnt = 0;
	stack<char> st;
	string res;
	for (int i = 0; i < n; ++i) {
		if (s[i] == ')' && !st.empty()) {
			if (st.top() == '(') {
				res += st.top();
				st.pop();
			}
			else st.push(s[i]);
		}
		else st.push(s[i]);
	}
	n = st.size();
	while (!st.empty() && st.top() == '(') {
		++cnt;
		res += st.top();
		st.pop();

	}
	// cout << n / 2 + cnt % 2 << endl;
	return res;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		if (n == 2 && s == "()") {
			cout << "NO" << endl;
			continue;
		}
		string a = string(n, '('), b = string(n, ')');
		string tmp = a + b;
		string res = "";
		for (int i = 0; i < n; ++i) res += "()";
		cout << "YES" << endl;
		if (tmp.find(s) != string::npos) {
			cout << res << endl;
		}
		else {
			cout << tmp << endl;
		}
	}
	return 0;
}

// ()() (())(())
// )( -> (())
// ))() -> (((())))
#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
	int n = s.size();
	for (int i = 0; i < n / 2; ++i) {
		if (s[i] != s[n - 1 - i]) return false;
	}
	return true;
}
int main() {
	string s; cin >> s;
	int sum = 0;
	for (char c : s) sum += c - '0';
	if (check(s) && sum % 10 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
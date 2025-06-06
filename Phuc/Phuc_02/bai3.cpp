#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	stack<int> st;
	vector<int> dp(s.size(), 0);
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[') {
			st.push(i);
		} else {
			if (!st.empty()) {
				int j = st.top();
				if ((s[i] == ')' && s[j] == '(') || (s[i] == ']' && s[j] == '[')) {
					st.pop();
					dp[i] = i - j + 1;
					if (j > 0) dp[i] += dp[j - 1];
					int cnt = 0;
					for (int k = i - dp[i] + 1; k <= i; ++k) {
						if (s[k] == '[') cnt++;
					}
					res = max(res, cnt);
				} else {
					while (!st.empty()) st.pop();
				}
			}
		}
	}
	cout << res << endl;
}
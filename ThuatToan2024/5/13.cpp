#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		stack<int> st;
		for (int i = 0; i < (int)s.size(); ++i){
			if (s[i] == '(') st.push(i);
			else if (s[i] == ')'){
				if (!st.empty() && s[st.top()] == '('){
					s[i] = '1';
					s[st.top()] = '0';
					st.pop();
				}
				else st.push(i);
			}
			else continue;
		}
		while (!st.empty()){
			cout << st.top() << endl;
			s[st.top()] = '2';
			st.pop();
		}
		for (int i = 0; i < (int)s.size(); ++i){
			if (s[i] == '2') cout << -1;
			else cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
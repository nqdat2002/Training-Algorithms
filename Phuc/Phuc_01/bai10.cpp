#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll a, ll b, string c) {
	if (c == "+") return a + b;
	if (c == "-") return a - b;
	if (c == "*") return a * b;
	return a / b;
}
bool isOperator(string c) {
	return c == "+" || c == "-" || c == "*" || c == "/";
}
ll calc2(vector<string> v, bool ok, int n){
	if (ok) reverse(v.begin(), v.end());
	stack<long long> st;
	for (int i = 0; i < n; ++i) {
		if (isOperator(v[i])) {
			ll x = st.top(); st.pop();
			ll y = st.top(); st.pop();
			ll z = 0;
			if (ok) z = calc(x, y, v[i]);
			else z = calc(y, x, v[i]);
			st.push(z);
		}
		else st.push(stoll(v[i]));
	}
	return st.top();
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<string> v;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			v.push_back(s);
		}
		cout << calc2(v, isOperator(v[0]), n) << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll a, ll b, string c){
	if(c == "+") return a + b;
	if(c == "-") return a - b;
	if(c == "*") return a * b;
	return a / b;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> v;
		for(int i = 0; i < n; ++i){
			string s; cin >> s;
			v.push_back(s);
		}
		stack<long long> st;
		for(int i = 0; i < n; ++i){
			if(v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/"){
				ll x = st.top(); st.pop();
				ll y = st.top(); st.pop();
				ll z = calc(y, x, v[i]);
				st.push(z);
			}
			else st.push(stoll(v[i]));
		}
		cout << st.top() << endl;
	}
	return 0;
}

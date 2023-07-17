#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<int> st;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '(')
				st.push(i);
			else if(s[i] == ')'){
				if(!st.empty() && s[st.top()] == '('){
					s[i] = '1';
					s[st.top()] = '0';
					st.pop();
				}
				else st.push(i);
			}
		}
		while(st.size()){
			s[st.top()] = 'x';
			st.pop();
		}
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == 'x') cout << -1;
			else cout << s[i];
		
		}
		cout << endl;
	}
}

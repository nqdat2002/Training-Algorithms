#include <bits/stdc++.h>
using namespace std;

int main(){
	queue<string> q;
	vector<string> v;
	v.push_back("0");
	v.push_back("1");
	q.push("0");
	q.push("1");
	while(q.size()){
		string s = q.front(); q.pop();
		if(s.size() > 16)
			break;
		q.push(s + "0");
		q.push(s + "1");
		v.push_back(s + "0");
		v.push_back(s + "1");
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(auto x: v){
			string st = x;
			reverse(st.begin(), st.end());
			string s = x + st;
			if(s.size() <= n){
				cout << s << " ";
			}
		}
		cout << endl;
	}	
}



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string s){
	int cnt = 0;
	for(int i = 0; i < s.length(); ++i) if(s[i] == '2') cnt++;
	return cnt > s.length() / 2;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		queue<string> q;
		q.push("1");
		q.push("2");
		int cnt = 0;
		while(cnt < n){
			string s = q.front(); q.pop();
			if(check(s)){
				cout << s << " ";
				cnt++;
			}
			q.push(s+ "0");
			q.push(s + "1");
			q.push(s + "2");
		}
		cout << endl;
	}
	return 0;
}

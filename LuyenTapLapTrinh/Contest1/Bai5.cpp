#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n, a[25];

bool check(){
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] == 2) ++cnt;
	}
	return cnt > (n / 2) && a[1] != 0;
}

void Try(int i){
	for(int j = 0; j <= 2; ++j){
		a[i] = j;
		if(i == n){
			if(check()){
				string t = "";
				for(int k = 1; k <= n; ++k){
					t += to_string(a[k]);
				}
				v.push_back(t);
			}
		}
		else Try(i + 1);
	}
}
int main(){
	v.push_back("2");
	v.push_back("22");
	
	for(int i = 3; i <= 13; ++i){
		n = i;
		memset(a, 0, sizeof(a));
		Try(1);
	}
	
	int t; cin >> t;
	while(t--){
		int m; cin >> m;
		for(int i = 0; i < m; ++i) cout << v[i] << " ";
		cout << endl;
	}
}

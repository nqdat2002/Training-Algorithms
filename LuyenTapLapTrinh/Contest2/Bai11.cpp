#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1001][1001];
int n, m;

pair<pair<int, int>, int>  max_area(int x[]){
	int res = 0, i = 0;
	int l = 0, r = 0;
	stack<int> st;
	while(i < m){
		if(st.empty() || x[i] >= x[st.top()]) st.push(i ++);
		else{
			int top = st.top(); st.pop();
			if(st.empty()){
				if(x[top] * i > res){
					res = x[top] * i;
					l = x[top], r = i;
				}
			} 
			else {
				if(x[top] * (i - st.top() - 1) > res){
					res = x[top] * (i - st.top() - 1);
					l = x[top], r = i - st.top() - 1;
				}
			}
		}
	}
	while(!st.empty()){
		int top = st.top(); st.pop();
		if(st.empty()){
			if(x[top] * i > res){
				res = x[top] * i;
				l = x[top], r = i;
			} 
		} 
		else {
			if(x[top] * (i - st.top() - 1) > res){
				res = x[top] * (i - st.top() - 1);
				l = x[top], r = i - st.top() - 1;
			}
		}
	}
	return {{l, r}, res};
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j) cin >> a[i][j];
		}
		int xx[n][n];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(i == 0) xx[i][j] = a[i][j];
				else if(a[i][j]) xx[i][j] = xx[i - 1][j] + 1;
				else xx[i][j] = 0;
			}
		}
		int res = 0, l = 0, r = 0;
		int resl = 0, resr = 0;
		for(int i = 0; i < n; ++i){
			pair<pair<int, int>, int>  p = max_area(xx[i]);
			if (p.second > res){
				res = p.second;
				resl = p.first.first;
				resr = p.first.second;
			}			
		}
//		cout << res << endl;
		cout <<  min(resl, resr) << " " << max(resl, resr) << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<ll, ll> > v(n);
		for(auto &x: v) cin >> x.first >> x.second;
		int f[n][2];
		f[0][0] = 0;
		f[0][1] = v[0].second;
		for(int i = 1; i < n; ++i){
			if(v[i].first == v[i - 1].first){
				f[i][0] = f[i - 1][1];
				f[i][1] = min(f[i - 1][0], f[i - 1][1]) + v[i].second;
			}
			else{
				f[i][0] = min(f[i - 1][0], f[i - 1][1]);
				f[i][1] = min(f[i - 1][0], f[i - 1][1]) + v[i].second;
			}
		}
		cout << min(f[n - 1][0], f[n - 1][1]) << endl;
	}
	return 0;
}

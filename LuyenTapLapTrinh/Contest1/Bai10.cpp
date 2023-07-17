#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll f[100];
//
//ll find(ll n, ll k){
//	if(n == 0){
//		return 1;
//	}
//	if(n == 1){
//		return 0;
//	}
//	if(k <= f[n - 1]){
//		return find(n - 1, k);
//	}
//	return find(n - 2, k - f[n - 1]) + find(n - 1, k);
//}
//int main(){
//	f[0] = f[1] = 1;
//	for(int i = 2; i < 46; ++i) f[i] = f[i - 1] + f[i - 2];
////	ll dp[46][46];
////	for(int i = 0; i < 46; ++i){
////		for(int j = 0; j < 46; ++j) 
////			dp[i][j] = find(i, j);
////	}
////	cout << f[45] << endl;
//	int t; cin >> t;
//	while(t--){
//		ll n, k; cin >> n >> k;
//		cout << find(n, k) << endl;
//	}
//}

ll n, k;
ll dp[46] = {1, 0};
ll f[46] = {1, 1};

ll find(ll n, ll k){
	if(n == 0) return 1;
	if(n == 1) return 0;
	if(f[n - 1] >= k) return find(n - 1, k);
	return (dp[n - 1] + find(n - 2, k - f[n - 1]));
}

int main(){
	for(int i = 2; i < 46; ++i) {
		f[i] = f[i - 2] + f[i - 1];
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		cout << find(n, k) << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int bs(int a[], int n, int s, int k){
	int l = 1, r = s;
	int res = -1;
	while(l <= r){
		int m = (l + r) >> 1;
		int sum = 0;
		for(int i = m; i <= s; ++i) sum += a[i];
		if(sum <= k){
			res = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return res;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, s, k; cin >> n >> s >> k;
		int a[n + 1];
		ll prefix[n + 1];
		for(int i = 1; i <= n; ++i) cin >> a[i];
		prefix[1] = a[1];
		for(int i = 2; i <= n; ++i){
			prefix[i] = prefix[i - 1] + a[i];
		}
		cout << bs(a, n, s, k) << endl;
	}
}

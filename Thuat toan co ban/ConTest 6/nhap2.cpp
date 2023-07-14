#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime(int n){
	if(n < 2) 
		return false;
	for(int i = 2; i <= sqrt(n); i ++)
		if(n % i == 0)
			return false;
	return true;
}
int degree2(int n, int p){
	int ans = 0;
	for(int i = p; i <= n; i *= p){
		ans += n / i;
	}
	return ans;
}
ll cnt(int n){
	ll res = 1;
	for(int i = 1; i <= n; i ++){
		if(prime(i)){
			res *= (degree2(n, i) + 1);
		}
	}
	return res;
}
int main(){
	int t;cin >> t;
	while(t--){
		int n; cin >> n;
		cout << cnt(n) << endl;
	}
	return 0;
}
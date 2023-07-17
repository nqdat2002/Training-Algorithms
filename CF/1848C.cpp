#include<bits/stdc++.h>
using namespace std;
bool checkZero(long long a[], int n){
	for(int i = 0; i < n; ++i) 
		if(a[i] != 0) return false;
	return true;
}
bool check(long long a[], long long b[], int n){
	for(int i = 0; i < n; ++i) 
		if(a[i] != b[i]) return false;
	return true;
}
int lcm(long long a, long long b){
	return a * b / __gcd(a, b);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long a[n], b[n];
		for(auto &x: a) cin >> x;
		for(auto &x: b) cin >> x;
		if(checkZero(a, n)) {
			cout << "YES" << endl;
			continue;
		}
		if(check(a, b, n)){
			cout << "YES" << endl;
			continue;
		}
		long long gcd_b = 1, gcd_a = 1;
		for(int i = 0; i < n; ++i){
			gcd_b = __gcd(gcd_b, b[i]);
			gcd_a = __gcd(gcd_a, a[i]);
		}
		
		if(gcd_b == gcd_a) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[12] = {};
void dp(int n, int a[]){
	if(n == 0) return;
	string s = to_string(n);
	int x = s.size();
	for(int i = 0; i < 10; ++i) a[i] += f[x - 1];
	for(int i = 0; i < x - 1; ++i) a[0] -= pow(10, i);
	for(int i = 0; i < x; ++i){
		int j = 0, p = 0, sum = 0;
		if(i == 0){
			p = j = 1;
			a[0] += f[x - 1 - i] * (s[i] - 48 - p);
		}
		sum = f[x - 1 - i] * (s[i] - 48 - p);
		
		for(;j < s[i] - 48; ++j) a[j] += pow(10, x - i - 1) + sum;
		a[j] += n % ((int)pow(10, x - i - 1)) + sum + 1;
		for(int k = j + 1; k < 10; ++k) a[k] += sum;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	for(int i = 0; i < 10; ++i) f[i] = i * pow(10, i - 1);
	int t; cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		int f1[21] = {}, f2[21] = {};
		dp(a - 1, f1);
		dp(b, f2);
		for(int i = 0; i < 10; ++i) cout << f2[i] - f1[i] << " ";
		cout << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int a[10] = {4, 7};
int n, k, b[10];
vector<ll> v;
void Try(int i){
	for(int j = 0; j <= 1; ++j){
		b[i] = j;
		if(i == n){
			ll x = 0;
			for(int k = 1; k <= n; ++k) x = x * 10 + a[b[k]];
			v.push_back(x);
		}
		else Try(i + 1);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	for(n = 1; n <= 9; ++n) Try(1);
	ll s = 0;
	ll x, y; cin >> x >> y;
	int i = 0;
	while(x <= y){
		if(x <= v[i] && y <= v[i]){
			s += (y - x + 1) * v[i];
			x = v[i] + 1;
		}
		else if(x <= v[i] && y >= v[i]){
			s += (v[i] - x + 1) * v[i];
			x = v[i] + 1;
		}
		else i++;
	}
	cout << s << endl;
	return 0;
}

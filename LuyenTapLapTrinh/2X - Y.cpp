#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll __lcm(ll a, ll b){
	return 1ll * (a * b) / __gcd(a, b);
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--){
		ll n, k; cin >> n >> k;
		ll a[n];
		for(auto &x: a) cin >> x;
		ll g1 = a[0];
		for(int i = 1; i < n; ++i){
			g1 = __gcd(g1, a[i]);
		}

		ll g2 = a[1] - a[0];
		for(int i = 2; i < n; ++i){
			g2 = __gcd(a[i] - a[0], g2);
		}

		if((k - a[0]) % g2 == 0 && k % g1 == 0){
			cout << "YES";
		}
		else cout << "NO";
		cout << endl;

	}
	return 0;
}
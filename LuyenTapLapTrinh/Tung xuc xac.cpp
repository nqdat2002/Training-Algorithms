#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f (int i, int s, vector<vector<ll>> &dp) {
	if (i == 1) 
		return dp[i][s] = (s >= 1 && s <= 6); 
	if (s <= 0) 
		return 0; 
	if (dp[i][s] != -1) 
		return dp[i][s]; 
	ll res = 0; 
	int end = s; 
	if (s > 6) end = 6; 
	for (int j = 1; j <= end; j++) { 
		res += f (i - 1, s - j, dp); 
	} 
	return dp[i][s] = res;
} 
ll numberOfTime (ll n, ll s) { 
	vector<vector<ll>> dp (n + 1, vector<ll> (s + 1, -1)); 
	return f (n, s, dp); 
} 
int main() { 
	ios_base::sync_with_stdio (0); 
	cin.tie (0); cout.tie (0); int t; cin >> t; 
	while (t--) { 
		ll n, s; cin >> n >> s; 
		cout << numberOfTime (n, s) << endl; 
	} 
}


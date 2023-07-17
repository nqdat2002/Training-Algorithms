#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int ba[105];
int memo[105][105];

long dp(int a, int b) {
	if (memo[a][b] != -1)
		return memo[a][b];
	if (a == b)
		return memo[a][b] = 1;
	memo[a][b] = dp(a + 1, b);
	for (int i = a + 1; i < b; ++i)
		if (ba[a + 1] < ba[i + 1])
			memo[a][b] = (memo[a][b] + dp(a + 1, i) * dp(i, b)) % mod;
	return memo[a][b];
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> ba[i];
	memset(memo, -1, sizeof(memo));
	cout << dp(0, n - 1) << endl;
	return 0;
}
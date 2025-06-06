#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[12], s[4], n = 12, S = 0;
bool vs[12];
int Try(int i, int index, int sum, int prev){
	int res = 1e9;
	if (i == 3){
		s[3] = S - s[0] - s[1] - s[2];
		int mx = INT_MIN, mn = INT_MAX;
		for (auto x: s) mx = max(mx, x), mn = min(mn, x);
		return min(res, mx - mn);
	}
	for (int j = prev; j < n; ++j){
		if (!vs[j]){
			vs[j] = true;
			if (index == 2){
				s[i] = sum + a[j];
				res = min(res, Try(i + 1, 0, 0, 0));
			}
			else res = min(res, Try(i, index + 1, sum + a[j], j + 1));
			vs[j] = false;
		}
	}
	return res;
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(s, 0, sizeof(s));
	memset(vs, false, sizeof(vs));
	for (int i = 0; i < n; ++i) cin >> a[i], S += a[i];
	cout << Try(0, 0, 0, 0) << endl;
	return 0;
}
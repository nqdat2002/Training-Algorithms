#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vs[100];
ll a[100], r[100];
void Try(int i, ll sum, int index, ll p, int n){
	if (sum > p) return;
	if (index == 2){
		r[0] += 1;
		return;
	}
	if (sum == p) Try(0, 0, index + 1, p, n);
	for (int j = i; j < n; ++j){
		if (!vs[j]){
			vs[j] = 1;
			Try(j + 1, sum + a[j], index, p, n);
			vs[j] = 0;
		}
	}
	return;
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll S = 0;
		for (int i = 0; i < n; ++i){
			cin >> a[i];
			S += a[i];
		}
		if (S % 3 != 0){
			cout << 0 << endl;
			continue;
		}
		memset(vs, false, sizeof(vs));
		memset(r, 0, sizeof(r));
		Try(0, 0, 0, S / 3, n);
		cout << r[0] << endl;
	}
	return 0;
}
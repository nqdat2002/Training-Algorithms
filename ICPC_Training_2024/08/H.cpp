#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, k; cin >> a >> b >> k;
	vector<int> res;
	for (int i = 100; i >= 1; --i){
		if (a % i == 0 && b % i == 0){
			res.push_back(i);
		}
	}
	cout << res[k - 1] << endl;
	return 0;
}
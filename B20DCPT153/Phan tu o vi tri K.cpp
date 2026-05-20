#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, x, p;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x == k) p = i + 1;
		}
		cout << p << endl;
	}
}
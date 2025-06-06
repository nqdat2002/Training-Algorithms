#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char find_char(ll n) {
	ll l = 3;
	int k = 0;
	while (l < n) {
		k++;
		l = 2 * l + (k + 3);
	}
	while (k >= 0) {
		ll prev_len = (l - (k + 3)) / 2;
		if (n <= prev_len) {
			l = prev_len;
			k--;
		} else if (n > prev_len + (k + 3)) {
			n -= prev_len + (k + 3);
			l = prev_len;
			k--;
		} else {
			if (n == prev_len + 1)
				return 'a';
			else
				return 'c';
		}
	}
	return 'c';
}
int main(int argc, char const *argv[]) {
	int n; cin >> n;
	cout << find_char(n) << endl;
	return 0;
}
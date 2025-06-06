#include <bits/stdc++.h>
using namespace std;
int n, k, c[100], cnt;
bool isprime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0) return false;
	}
	return true;
}
void Try(int i) {
	for (int j = c[i - 1] + 1; j <= n - k + i; j++) {
		c[i] = j;
		if (i == k) {
			cnt ++;
			if (isprime(cnt)) {
				cout << cnt << ": ";
				for (int h = 1; h <= k; ++h) cout << c[h] << " ";
				cout << endl;
			}
		}
		else Try(i + 1);
	}
}
int main() {
	cin >> n >> k;
	cnt = 0;
	Try(1);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, c[100], cnt;
ll fibo[100];
bool check[100];

bool isFibo(int x) {
	for (int i = 1; i <= 90; ++i) {
		if (fibo[i] == x) return true;
	}
	return false;
}
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!check[j]) {
			c[i] = j;
			check[j] = true;
			if (i == n) {
				cnt += 1;
				if (isFibo(cnt)) {
					cout << cnt << ": ";
					for (int h = 1; h <= n; ++h) cout << c[h] << " ";
					cout << endl;
				}
			}
			else Try(i + 1);
			check[j] = false;
		}
	}
}
int main() {
	fibo[0] = 0; fibo[1] = 1;
	for (int i = 2; i <= 90; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	memset(check, false, sizeof(check));
	cnt = 0;
	cin >> n;
	Try(1);
}
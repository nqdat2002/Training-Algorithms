#include <bits/stdc++.h>
using namespace std;
int n, k, m, c[100], cnt;
void Try(int i) {
	for (int j = c[i - 1] + 1; j <= n - k + i; j++) {
		c[i] = j;
		if (i == k) {
			cnt ++;
			if (cnt % m == 0) {
				for (int h = 1; h <= k; ++h) cout << c[h] << " ";
				cout << endl;
			}
		}
		else Try(i + 1);
	}
}
int main(){
	cin >> n >> k >> m;
	cnt = 0;
	Try(1);
}
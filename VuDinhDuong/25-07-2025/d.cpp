#include <bits/stdc++.h>
using namespace std;
int n, m, c[20], cnt;
bool vs[20];
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!vs[j]) {
			c[i] = j;
			vs[j] = true;
			if (i == n) {
				cnt ++;
				if (cnt % m == 0) {
					for (int h = 1; h <= n; ++h) cout << c[h] << " ";
					cout << endl;
				}
			}
			else Try(i + 1);
			vs[j] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	memset(vs, false, sizeof(vs));
	cnt = 0;
	Try(1);
}
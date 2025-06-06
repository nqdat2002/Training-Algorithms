#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { 1, 0, -1, 0 }; 
const int dy[4] = { 0, 1, 0, -1 };
int n, xa[55], ya[55], xb[55], yb[55], xc[105], yc[105], xd[55], yd[55], xe[55], ye[55], f[105][105]; 
long long d[105][105];

void dfs(int x, int y) {
	f[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (0 <= xx && xx <= 2 * n + 1 && 0 <= yy && yy <= 2 * n + 1) {
			if (d[y][x] == d[yy][xx] && !f[yy][xx]) 
				dfs(xx, yy);
		}
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> xa[i] >> yb[i] >> xb[i] >> ya[i];
			xc[2 * i] = xa[i], yc[2 * i] = ya[i], xc[2 * i + 1] = xb[i], yc[2 * i + 1] = yb[i];
		}
		sort(xc, xc + 2 * n);
		sort(yc, yc + 2 * n);
		memset(xd, 0, sizeof(xd));
		memset(yd, 0, sizeof(yd));
		memset(xe, 0, sizeof(xe));
		memset(ye, 0, sizeof(ye));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if (xa[i] == xc[j] && !xd[i]) xa[i] = j + 1, xd[i] = 1;
				if (ya[i] == yc[j] && !yd[i]) ya[i] = j + 1, yd[i] = 1;
				if (xb[i] == xc[j] && !xe[i]) xb[i] = j + 1, xe[i] = 1;
				if (yb[i] == yc[j] && !ye[i]) yb[i] = j + 1, ye[i] = 1;
			}
		}
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++) {
			for (int j = xa[i]; j < xb[i]; j++) {
				for (int k = ya[i]; k < yb[i]; k++) {
					d[j][k] += (1LL << i);
				}
			}
		}
		int res = 0;
		for (int i = 0; i <= 2 * n + 1; i++) {
			for (int j = 0; j <= 2 * n + 1; j++) {
				if (!f[i][j]) {
					dfs(j, i); 
					res++;
				}
			}
		}
		cout << res << endl;
	}
}

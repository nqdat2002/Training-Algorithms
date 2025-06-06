#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, c[100], cnt;
ll fibo[100];
vector<vector<int>> res;
bool isFibo(int x){
	for (int i = 1; i <= 90; ++i){
		if (fibo[i] == x) return true;
	}
	return false;
}
void Try(int i) {
	for (int j = c[i - 1] + 1; j <= n - k + i; j++) {
		c[i] = j;
		if (i == k) {
			cnt += 1;
			if (isFibo(cnt)){
				cout << cnt << ": ";
				for (int h = 1; h <= k; ++h) cout << c[h] << " ";
				cout << endl;
			}
		}
		else Try(i + 1);
	}
}
int main() {
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= 90; ++i){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cnt = 0;
	cin >> n >> k;
	Try(1);
}
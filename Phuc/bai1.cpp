#include <bits/stdc++.h>
using namespace std;
int n, k, a[900000], cnt;
void Try(int i){
	for (int j = 0; j <= 1; ++j){
		a[i] = j;
		if (i == n){
			if (cnt == 0) {
				for (int h = 1; h <= n; ++h) cout << a[h];
				cout << endl;
			}
			else if (cnt != 0 && cnt % k == 0){
				for (int h = 1; h <= n; ++h) cout << a[h];
				cout << endl;
			}
			cnt += 1;
		}
		else Try(i + 1);
	}
}
int main(){
	cin >> n >> k;
	cnt = 0;	
	Try(1);
}
#include <bits/stdc++.h>
using namespace std;
int n, k, c[24];
bool pr(int x){
	if(x < 2) return false;
	for(int i = 2; i <= sqrt(x); ++i){
		if(x % i == 0)
			return false;
	}
	return true;
}
int cnt = 0;
void Try(int i){
	for(int j = c[i - 1] + 1; j <= n - k + i; ++j){
		c[i] = j;
		if (i == k){
			cnt ++;
			if(pr(cnt)){
				cout << cnt << ": ";
				for(int kk = 1; kk <= k; ++kk){
					cout << c[kk] << " ";
				}
				cout << endl;
			}
		}
		else Try(i + 1);
	}
}
int main(){
	cin >> n >> k;
	Try(1);
}

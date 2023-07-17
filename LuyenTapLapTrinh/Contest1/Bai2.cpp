#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++i){
		a[i] = i;
	}
	int cnt = 1;
	do{
		cout << cnt << ": ";
		cnt += 1;
		for(int i = 1; i <= n; ++i) cout << a[i] << " ";
		cout << endl;
	}while(next_permutation(a + 1, a + n + 1));
}

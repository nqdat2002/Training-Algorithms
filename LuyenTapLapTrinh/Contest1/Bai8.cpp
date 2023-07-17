#include <bits/stdc++.h>
using namespace std;
int a[6 + 1], b[6 + 1];
int n;
bool ok;
void CHL(){
	bool x = false;
	for(int i = n; i >= 1; --i){
		if(a[i] != n){
			a[i] ++;
			for(int j = i + 1; j <= n; ++j) a[j] = 1;
			x = true;
			break;
		}
	}
	if(x == false) ok = true;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		b[i] = i;
		a[i] = 1;
	}
	do{
		ok = false;
		while(!ok){
			for(int i = 1; i <= n; ++i) cout << char(b[i] + 64);
			for(int i = 1; i <= n; ++i) cout << a[i];
			cout << endl;
			CHL();
		}
		for(int i = 1; i <= n; ++i) a[i] = 1;
		
	}while(next_permutation(b + 1, b + n + 1));
}

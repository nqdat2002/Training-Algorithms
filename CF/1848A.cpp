#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		int x[k], y[k];
		int x1, y1; cin >> x1 >> y1;
		for(int i = 0; i < k; ++i){
			cin >> x[i] >> y[i];
		}
		bool cnt = true;
		for(int i = 0; i < k; ++i){
			int _x = abs(x1 - x[i]), _y = abs(y1 - y[i]);
			if((_x + _y) % 2 == 0) cnt = false;
		}
		if(cnt) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		long long y;
		cin >> y;
		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) 
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
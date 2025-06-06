#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		vector<string> v;
		stringstream ss(s);
		string a;
		while (ss >> a){
			reverse(a.begin(), a.end());
			v.push_back(a);
		}
		for (auto x: v) cout << x << " ";
		cout << endl;
	}
}
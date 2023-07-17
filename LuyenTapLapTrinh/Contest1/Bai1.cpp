#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	multiset<int> s1, s2;
	int a[n];
	for(int &x: a){
		cin >> x;
		if(x % 2 == 0) s2.insert(x);
		else s1.insert(x);
	}
	
	for(int i = 0; i < n; ++i){
		if(a[i] % 2 == 1){
			cout << *s1.rbegin() << " ";
			auto it = s1.find(*s1.rbegin());
			s1.erase(it);
		}
		else{
			cout << *s2.begin() << " ";

			s2.erase(s2.begin());
		}
	}
	
}

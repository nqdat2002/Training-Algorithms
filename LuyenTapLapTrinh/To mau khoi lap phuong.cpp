#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		sum += x;
	}
	ll res = 1;
	for(int i = 1; i <= sum; ++i) if(i % 2 == 1) res *= i;
	cout << res << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, a[25];
vector<int> v;

void init(){
	v.clear();
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		int x; cin >> x;
		v.push_back(x);
	}
	sort all(v);
}

void output(){
	for(int i = 1; i <= k; i ++)
		cout << v[a[i] - 1] << " ";
	cout << endl;
}

void Try(int i){
	for(int j = a[i - 1] + 1; j <= n - k + i; j ++){
		a[i] = j;
		if(i == k) output();
		else Try(i + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		init();
		Try(1);
	}
	return 0;
}

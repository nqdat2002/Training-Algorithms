#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n + 1], cnt[n + 5];
		memset(cnt, 0, sizeof(cnt));
		v.clear();
		vector<int> aa;
		v.push_back(aa);
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			cnt[i] = 0;
			v.push_back(aa);
		}
		for(int i = 1; i <= n; ++i){
			v[a[i]].push_back(i - cnt[a[i]] - 1);
			cnt[a[i]] = i;
		}
		int m = INT_MAX;
		for(int i = 1; i <= k; ++i){
			v[i].push_back(n - cnt[i]);
			sort(v[i].rbegin(), v[i].rend());
			int ans = v[i][0] / 2;
			ans = max(ans, v[i][1]);
			m = min(ans, m);
		}
		cout << m << endl;
	}
	return 0;
}
 

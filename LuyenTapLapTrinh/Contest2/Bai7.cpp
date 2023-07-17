#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 50005;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	int n; cin >> n;
	int st[nmax], cnt[nmax];
	int res = 0, last = 0;
	for(int i = 1; i <= n; ++i){
		int x; cin >> x;
		int j = 0, s = 0;
		while (last > 0 && st[last] <= x){
			j += cnt[last];
			if(st[last] == x) s = 1;
			last -= 1;
		}
		if(st[last] > x) j += 1;
		if(i > 1) res += j;
		if(s == 0){
			last += 1;
			st[last] = x;
			cnt[last] = 1;
		}
		else{
			last += 1;
			cnt[last] += 1;
		}
	}
	cout << res << endl;
	return 0;
}

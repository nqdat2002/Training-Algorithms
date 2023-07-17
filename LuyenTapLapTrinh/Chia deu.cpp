#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k;
int a[20];
int cnt;

void init(){
	cin >> n >> k;
	cnt = 0;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i ++){
		int x; cin >> x;
		a[i] = a[i - 1] + x;
	}
}
void Try(int u, int b, int e, int k){
	if(b > e || k == 0)
		return;
	if(k == 1){
		if(a[e] - a[b - 1] == u){
			cnt ++;
			return;
		}
		else return;
	}
	int s = b;
	for (int i = b; i <= e; i ++){
		if (a[i] - a[s - 1] == u)
			Try(u, i + 1, e, k - 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	if(k == 1) cnt = 1;
	else{
		for(int i = 1; i <= n; i ++){
			int x = a[i];
			Try(x, i + 1, n, k - 1);
		}
	}
	cout << cnt << endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1001][1001], b[1001][1001];
int n, m;
void bfs(){
	queue<pair<int, int> > q;
	q.push({1, 1});
	b[1][1] = 0;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		if(x == n && y == m){
			cout << b[x][y] << endl;
			return;
		}
		if(x + 1 <= n){
			int i = x + abs(a[x][y] - a[x + 1][y]), j = y;
			if(i <= n && b[i][j] == 100000){
				b[i][j] = b[x][y] + 1;
				q.push({i, j});
			}
		}
		if(y + 1 <= m){
			int i = x , j = y + abs(a[x][y] - a[x][y + 1]);
			if(j <= m && b[i][j] == 100000){
				b[i][j] = b[x][y] + 1;
				q.push({i, j});
			}
		}
		int i = x + abs(a[x][y] - a[x + 1][y + 1]), j = y + abs(a[x][y] - a[ 1 + x][y + 1]);
		if(i <= n && j <= m && b[i][j] == 100000){
			b[i][j] = b[x][y] + 1;
			q.push({i, j});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) cin >> a[i][j], b[i][j] = 100000;
		bfs();
	}
	return 0;
}

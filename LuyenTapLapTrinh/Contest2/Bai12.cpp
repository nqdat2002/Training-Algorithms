#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const pair<int, int> KM[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
const pair<int, int> HM[] = {{-2, -1}, {2, -1}, {-1, -2}, {-1, 2}, {2, 1}, {-2, 1}, {1, 2}, {1, -2}};
vector<vector<int> > vsK(101, vector<int>(101, -1)), vsH(101, vector<int>(101, -1));
vector<vector<char> > a(101, vector<char>(101, '#'));
int n;
pair<int, int> King, Horse;
bool move(int x, int y){
	return !(x < 0 || x > n || y > n || y < 0 || a[x][y] == '#');
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'T') King = {i, j};
			if(a[i][j] == 'M') Horse = {i, j};
		}
	}
	
	queue<pair<pair<int, int>, int> > q;
	q.push({King, 0});
	vsK[King.first][King.second] = 0;
	while(!q.empty()){
		int x = q.front().first.first, y = q.front().first.second, cnt = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; ++i){
			int xx = x + KM[i].first, yy = y + KM[i].second;
			if(move(xx, yy) && vsK[xx][yy] == -1){
				vsK[xx][yy] = cnt + 1;
				q.push({{xx, yy}, cnt + 1});
			}
		}
	}
	
	while(q.size()) q.pop();
	q.push({Horse, 0});
	vsH[Horse.first][Horse.second] = 0;
	while(!q.empty()){
		int x = q.front().first.first, y = q.front().first.second, cnt = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; ++i){
			int xx = x + HM[i].first, yy = y + HM[i].second;
			if(move(xx, yy) && vsH[xx][yy] == -1){
				vsH[xx][yy] = cnt + 1;
				q.push({{xx, yy}, cnt + 1});
			}
		}
	}
	
	int res = 1e9;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(vsK[i][j] != -1 && vsH[i][j] != -1){
				int cz = abs(vsK[i][j] - vsH[i][j]);
				if(!(cz & 1))
					res = min(res, max(vsK[i][j], vsH[i][j]));
			}
		}
	}
	if(res == 1e9) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}

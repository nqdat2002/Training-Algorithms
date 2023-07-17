#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

char a[105][105];
int n;
int vs[105][105];

bool check(int x, int y){
	return (x <= n && x >= 1 && y <= n && y >= 1 && a[x][y] != 'X');
}

void bfs(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j) cin >> a[i][j];
	}
	memset(vs, -1, sizeof(vs));
	
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	a1 += 1;
	a2 += 1;
	b1 += 1;
	b2 += 1;
	
	queue<pair<int, int> > q;
	q.push({a1, b1});
	vs[a1][b1] = 0;
	while(q.size()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int j = y + 1; j <= n; ++j){
            if(check(x, j) && vs[x][j] == -1){
                vs[x][j] = vs[x][y] + 1;
                q.push({x, j});
            }
            else break;
        }
        for(int j = y - 1; j >= 1; --j){
            if(check(x, j) && vs[x][j] == -1){
                vs[x][j] = vs[x][y] + 1;
                q.push({x, j});
            }
            else break;
        }
        for(int j = x + 1; j <= n; ++j){
            if(check(j, y) && vs[j][y] == -1){
                vs[j][y] = vs[x][y] + 1;
                q.push({j, y});
            }
            else break;
        }
        for(int j = x - 1; j >= 1; --j){
            if(check(j, y) && vs[j][y] == -1){
                vs[j][y] = vs[x][y] + 1;
                q.push({j, y});
            }
            else break;
        }
	}
	cout << vs[a2][b2] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--){
		bfs();
	}
	return 0;
}

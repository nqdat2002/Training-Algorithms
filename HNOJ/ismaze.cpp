#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int maxN  = 3001;

int n;
vector<vector<char> > a(maxN, vector<char>(maxN, '0'));
vector<vector<bool> > visit(maxN, vector<bool>(maxN, false));

vector <int> slicks;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    int sizeSlicks = 1;
    queue < pair <int, int> > q;
    q.push({sx, sy});
    visit[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if (u > n || u < 1) continue;
            if (v > n || v < 1) continue;
            if (a[u][v] == '1') continue; 

            if (a[u][v] == '0' && !visit[u][v]) {
                ++sizeSlicks;
                visit[u][v] = true;
                q.push({u, v});
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] == '0' && !visit[i][j])
                bfs(i, j);
    for (int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i][j] == '0' && !visit[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}

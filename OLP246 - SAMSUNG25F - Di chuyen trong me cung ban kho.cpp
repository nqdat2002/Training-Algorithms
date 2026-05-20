#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Point {
    int x, y;
};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int n, m; cin >> n >> m;
    int cx, cy, dx_dest, dy_dest;
    cin >> cx >> cy >> dx_dest >> dy_dest;
    cx--; cy--; dx_dest--; dy_dest--; 

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<bool>> vs(n, vector<bool>(m, false));
    queue<Point> q[3];
    dist[cx][cy] = 0;
    q[0].push({cx, cy});
    int curr_dist = 0;
    int u_q = 1;
    while (u_q > 0) {
        int idx = curr_dist % 3;
        if (q[idx].empty()) {
            curr_dist++;
            continue;
        }
        Point curr = q[idx].front();
        q[idx].pop();
        u_q--;
        int u = curr.x;
        int v = curr.y;

        if (dist[u][v] < curr_dist) continue;
        if (u == dx_dest && v == dy_dest) break;
        for (int i = 0; i < 4; ++i) {
            int nx = u + dx[i];
            int ny = v + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                if (dist[nx][ny] > curr_dist + 1) {
                    dist[nx][ny] = curr_dist + 1;
                    q[(curr_dist + 1) % 3].push({nx, ny});
                    u_q++;
                }
            }
        }
        int r_min = max(0, u - 2), r_max = min(n - 1, u + 2);
        int c_min = max(0, v - 2), c_max = min(m - 1, v + 2);

        for (int nx = r_min; nx <= r_max; ++nx) {
            for (int ny = c_min; ny <= c_max; ++ny) {
                if (grid[nx][ny] == '.' && !vs[nx][ny]) {
                    if (dist[nx][ny] > curr_dist + 2) {
                        dist[nx][ny] = curr_dist + 2;
                        vs[nx][ny] = true; 
                        q[(curr_dist + 2) % 3].push({nx, ny});
                        u_q++;
                    }
                }
            }
        }
    }
    if (dist[dx_dest][dy_dest] == INF) cout << -1 << "\n";
    else cout << dist[dx_dest][dy_dest] << "\n";
    return 0;
}

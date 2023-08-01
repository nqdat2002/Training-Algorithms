#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int, int> > vpii;
#define mp make_pair
#define pb push_back

vpii adjList[4000];
int colour[4000], bad = 0;

int dfs(int u, int c) {
    if (colour[u] != -1) {
        if (colour[u] != c) bad = 1;
        return 0;
    }
    colour[u] = c;
    for (pair<int, int> p: adjList[u]) dfs(p.first, c ^ p.second);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        for (auto &x: adjList) x.clear();

        for (int i = 0; i < k; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            adjList[min(x1, x2)].push_back({n + min(y1, y2), (x1 + y1 != x2 + y2)});
            adjList[n + min(y1, y2)].push_back({min(x1, x2), (x1 + y1 != x2 + y2)});
        }
        bad = 0;
        fill(colour, colour + n + m, -1), bad = 0;
        for (int i = 0; i < n + m; i++) {
            if (colour[i] == -1) dfs(i, 0);
        }
        cout << (bad ? "NO" : "YES") << endl;
    }
    return 0;
}
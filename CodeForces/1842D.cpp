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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int n, m;
long long dis[100][100];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        dis[u][v] = dis[v][u] = w;
    }
    for (int i = 0; i < n; i++) dis[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    if (dis[0][n - 1] > 1e18)
        cout << "inf", exit(0);
    int ord[100];
    iota(ord, ord + n, 0);
    sort(ord + 1, ord + n, [](int a, int b) {
        return dis[0][a] < dis[0][b];
    });
    string s(n, '0');
    vector<pair<string, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        int u = ord[i], v = ord[i + 1];
        s[u] = '1';
        ans.emplace_back(s, dis[0][v] - dis[0][u]);
        if (v == n - 1) break;
    }
    cout << dis[0][n - 1] << ' ' << ans.size() << '\n';
    for (auto [s, t] : ans)
        cout << s << ' ' << t << '\n';
    return 0;
}
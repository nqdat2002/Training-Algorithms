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

const int maxn = 1e5 + 10;
vector <int> adj[maxn];
ll res, f[maxn], g[maxn];

void dfs(int u, int par) {
    priority_queue<ll> q;
    for (int v : adj[u]) {
        if (v == par)
            continue;
        dfs(v, u);
        q.push(f[v]);
    }
    f[u] = 0;
    if (!q.empty())
        f[u] = 1 + q.top();
    if (q.size() >= 2) {
        g[u] = 2 + q.top();
        q.pop();
        g[u] += q.top();
    }
    res = max(res, max(f[u], g[u]));
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        cout << res << endl;
    }
    return 0;
}

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

ll bfs(ll source, ll sink, vector<vector<ll>> &g, ll n, vector<ll> &parent) {
    queue<pair<ll, ll>> q;
    vector<bool> vis(n, 0);
    q.push({source, INT_MAX});
    vis[source] = 1;

    while (!q.empty()) {
        source = q.front().first;
        ll cap = q.front().second;
        q.pop();

        for (int i = 0; i < n; i++) {
            if (g[source][i] && !vis[i]) {
                parent[i] = source;
                if (i == sink)
                    return min(cap, g[source][i]);
                q.push({i, min(cap, g[source][i])});
                vis[i] = 1;
            }
        }
    }
    return 0;
}

ll ford_fulkerson(ll source, ll sink, vector<vector<ll>> &g, ll n) {
    ll flow = 0;
    vector<ll> parent(n, -1);

    ll min_cap;
    while (min_cap = bfs(source, sink, g, n, parent)) {
        flow += min_cap;

        ll u, v = sink;
        while (v != source) {
            u = parent[v];
            g[u][v] -= min_cap;
            g[v][u] += min_cap;
            v = u;
        }
    }
    return flow;
}

ll solve(ll n, ll m, vector<vector<ll>> e, ll st, ll en) {
    vector<vector<ll>> g(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        g[e[i][0]][e[i][1]] += e[i][2];
        g[e[i][1]][e[i][0]] += e[i][2];
    }

    return ford_fulkerson(st, en, g, n + 1);
}

void subtask2() {
    // Using Ford_fulkerson algorithms
    ll n, m, u, v, w, st, en;
    scanf("%lld %lld %lld %lld", &n, &m, &st, &en);
    vector<vector<ll>> Edges;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        Edges.push_back({u, v, w});
    }
    cout << solve(n, m, Edges, st, en) << endl;
}

// -------------------------------------------------------------------//////////////////

const int inf = 1 << 29;

struct edge{
    int x, y, cap, flow;
};

struct Flow {
    int n, S, T;
    vector < vector <int> > a;
    vector <int> cur, d;
    vector <edge> e;

    Flow() {}
    Flow(int _n, int _S, int _T) {
        n = _n; S = _S; T = _T;
        a = vector < vector <int> >(n + 1);
        cur = vector <int>(n + 1);
        d = vector <int>(n + 1);
    }

    void addEdge(int x, int y, int _cap) {
        edge e1 = {x, y, _cap, 0};
        edge e2 = {y, x, 0, 0};
        a[x].push_back(e.size()); e.push_back(e1);
        a[y].push_back(e.size()); e.push_back(e2);
    }

    int bfs() {
        queue <int> q;
        for (int i = 1; i <= n; i++) d[i] = -1;
        q.push(S); d[S] = 0;
        while (!q.empty() && d[T] < 0) {
            int x = q.front(); q.pop();
            for (int i = 0; i < int(a[x].size()); i++) {
                int id = a[x][i], y = e[id].y;
                if (d[y] < 0 && e[id].flow < e[id].cap)
                    q.push(y), d[y] = d[x] + 1;
            }
        }
        return d[T] >= 0;
    }

    int dfs(int x, int val) {
        if (!val) return 0;
        if (x == T) return val;
        for (; cur[x] < int(a[x].size()); cur[x]++) {
            int id = a[x][cur[x]], y = e[id].y;
            if (d[y] != d[x] + 1) continue;
            int pushed = dfs(y, min(val, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow() {
        int res = 0;
        while (bfs()) {
            for (int i = 1; i <= n; i++) cur[i] = 0;
            while (1) {
                int val = dfs(S, inf);
                if (!val) break;
                res += val;
            }
        }
        return res;
    }
};

void subtask1() {
    int n, m, S, T, x, y, z;
    cin >> n >> m >> S >> T;
    Flow u(n, S, T);
    while (m--) {
        cin >> x >> y >> z;
        u.addEdge(x, y, z);
    }
    cout << u.maxFlow() << endl;
}

// ----------------------------------------------------------------------------//

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

void subtask3() {
    // Using Dinic Algorithm
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Dinic g(n + 5, s, t);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    cout << g.flow() << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--) {
        subtask3();
    }
    return 0;
}

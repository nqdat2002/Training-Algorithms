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

struct Edge {
    int u, v;
    ll c;
    Edge(int _u, int _v, ll _c): u(_u), v(_v), c(_c) {};
};

struct Dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

int n, m, totalWeight = 0;
vector < Edge > edges;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    FileIO();

    cin >> n;
    vector<pair<int, int> > a;
    a.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        a.push_back({u, v});
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                ll dist = ((a[i].first - a[j].first) * (a[i].first - a[j].first)
                    + (a[i].second - a[j].second) * (a[i].second - a[j].second));
                edges.push_back({i, j, dist});
            }
        }
    }

    dsu.init(n);
    sort(edges.begin(), edges.end(), [](Edge & x, Edge & y) {
        return x.c < y.c;
    });
    int res = 0;
    for (auto e : edges) {
        if (!dsu.join(e.u, e.v)) continue;
        totalWeight += e.c;
        res = e.c;
    }
    cout << res << endl;
    return 0;
}
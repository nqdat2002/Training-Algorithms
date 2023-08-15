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

#define fi first
#define se second
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

const int N = 2e5 + 5;
const int INF = 1e9;
ll n, m;
vector <pair<ll, ll> > adj[N];

ll dis[N];

ll prim(int s) {
    ll ret = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        ll curDis = top.fi; ll u = top.se;

        if (curDis != dis[u]) continue;
        ret += dis[u]; 
        dis[u] = -INF;
        for (auto &e : adj[u]) {
            int v = e.fi; int c = e.se;
            if (dis[v] > c) {
                dis[v] = c;
                q.push({ dis[v], v});
            }
        }
    }
    return ret;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (ll i = 0; i < N; ++i) adj[i].clear();
        for (ll i = 1; i <= m; i++) {
            ll u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        cout << prim(1) << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fi first
#define se second
typedef pair<int, int> ii;
typedef vector<int> v;
typedef vector<string> vs;
const ll oo = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int n, m;
vector<ii> a[N];
int d[N];
unordered_set<int> p[N];
struct cmp
{
    bool operator()(ii x, ii y)
    {
        return x.fi >= y.fi;
    }
};
void dijkstra(int u){
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[u] = 0;
    priority_queue<ii, vector<ii>, cmp> pq;
    pq.push({0, u});
    while (!pq.empty())
    {
        int k = pq.top().se;
        pq.pop();
        for (auto x : a[k])
        {
            int s = x.se;
            int d_k_s = x.fi;
            if (d[k] + d_k_s < d[s])
            {
                d[s] = d[k] + d_k_s;
                pq.push({d[s], s});
                p[s].clear();
                p[s].insert(k);
            }
            else if (d[k] + d_k_s == d[s])
                p[s].insert(k);
        }
    }
}
int solve(int u)
{
    int ans = 0;
    if (p[u].size() == 0)
        return 1;
    for (int x : p[u])
    {
        ans += solve(x);
    }
    return ans;
}
main(){
    int  t = 1;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < N; ++i) a[i].clear();
        while (m--)
        {
            int x, y, c;
            cin >> x >> y >> c;
            a[x].push_back({c, y});
            a[y].push_back({c, x});
        }
        dijkstra(1);
        cout << d[n] << " ";
        cout << solve(n) << endl;
    }
    return 0;
}

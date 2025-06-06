#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int> adj[maxn], rev[maxn];
bool vs[maxn];
stack<int> st;
int comp[maxn], n, m;
void dfs1(int u) {
    vs[u] = true;
    for (int v : adj[u]) 
        if (!vs[v]) dfs1(v);
    st.push(u);
}
void dfs2(int u, int label) {
    comp[u] = label;
    for (int v : rev[u]) {
        if (comp[v] == -1) dfs2(v, label);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    memset(vs, false, sizeof(vs));
    for (int i = 1; i <= n; i++)
        if (!vs[i]) dfs1(i);
    memset(comp, -1, sizeof(comp));
    int label = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (comp[u] == -1)
            dfs2(u, label++);
    }
    vector<int> indegree(label, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (comp[u] != comp[v])
                indegree[comp[v]]++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < label; i++)
        if (indegree[i] == 0) ++cnt;
    cout << cnt << endl;
}
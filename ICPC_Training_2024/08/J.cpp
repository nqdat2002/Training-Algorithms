#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int n, m, parent[N], weight[N];

void make(int u) {
	parent[u] = u;
	weight[u] = 0;
}

int find(int u) {
	if (u == parent[u]) return u;
	int p = find(parent[u]);
	weight[u] += weight[parent[u]];
	parent[u] = p;
	return parent[u];
}

void merge(int u, int v, int w) {
	int fu = find(u);
	int fv = find(v);

	if (fu != fv) {
		parent[fv] = fu;
		weight[fv] += (weight[u] - weight[v] + w);
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) make(i);
		while (m --) {
			char type; cin >> type;
			int u, v, w;
			if (type == '!') {
				cin >> u >> v >> w;
				merge(u, v, w);
			} else {
				cin >> u >> v;
				if (find(u) == find(v)) {
					cout << weight[v] - weight[u] << endl;
				}
				else cout << "UNKNOWN" << endl;
			}
		}
	}
	return 0;
}
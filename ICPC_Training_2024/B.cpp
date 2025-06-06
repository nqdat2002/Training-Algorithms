#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
ll sz[maxn], p[maxn];

bool check(int a) {
    bool ans = 1;
    while (a) {
        if (a % 10 != 7 and a % 10 != 4) ans = 0;
        a /= 10;
    }
    return ans;
}

int find(int v) {
    if (p[v] == v){
        return v;
    }
    return p[v] = find(p[v]);
}

void merge(int x, int y) {
    if (sz[y] > sz[x]) {
        swap(x, y);
    }
    p[y] = x;
    sz[x] += sz[y];
    sz[y] = 0;
    return;
}

int main() {
    ll n; cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (check(w)) continue;
        int x = find(v), y = find(u);
        merge(x, y);
    }
    ll ans = n * (n - 1) * (n - 2);
    for (int i = 1; i <= n; i++){
        ans -= 2 * sz[i] * (sz[i] - 1) * (n - sz[i]) + sz[i] * (sz[i] - 1) * (sz[i] - 2);
    }
    cout << ans << endl;
    return 0;
}
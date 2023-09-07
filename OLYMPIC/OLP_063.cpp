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

const int N = 1e5 + 5;
struct Node {
    ll lazy;
    ll sum;
} tree[N * 4];
int a[N];

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].sum = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
}

void update(int id, int l, int r, int u, int v, ll val) {
    if (tree[id].lazy != 0) {
        tree[id].sum += (r - l + 1) * tree[id].lazy;
        if (l != r) {
            tree[2 * id].lazy += tree[id].lazy;
            tree[2 * id + 1].lazy += tree[id].lazy;
        }
        tree[id].lazy = 0;
    }

    if (l > v || r < u) {
        return;
    }

    if (l >= u && r <= v) {
        tree[id].sum += (r - l + 1) * val;

        if (l != r) {
            tree[2 * id].lazy += val;
            tree[2 * id + 1].lazy += val;
        }
        return;
    }

    int m = (l + r) >> 1;
    update(2 * id, l, m, u, v, val);
    update(2 * id + 1, m + 1, r, u, v, val);

    tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
}

ll get(int id, int l, int r, int u, int v) {
    if (tree[id].lazy != 0) {
        tree[id].sum += (r - l + 1) * tree[id].lazy;

        if (l != r) {
            tree[2 * id].lazy += tree[id].lazy;
            tree[2 * id + 1].lazy += tree[id].lazy;
        }
        tree[id].lazy = 0;
    }
    if (l > v || r < u) {
        return 0;
    }
    if (l >= u && r <= v) {
        return tree[id].sum;
    }
    int m = (l + r) >> 1;
    ll leftSum = get(2 * id, l, m, u, v);
    ll rightSum = get(2 * id + 1, m + 1, r, u, v);
    return leftSum + rightSum;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    FileIO();

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 2) {
            int val; cin >> val;
            update(1, 1, n, u, v, val);
        } else {
            cout << get(1, 1, n, u, v) << endl;
        }
    }
    return 0;
}

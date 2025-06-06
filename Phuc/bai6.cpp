#include <bits/stdc++.h>
using namespace std;
struct Node {
    long long sum, pref, suff, maxSum;
};
int n, q;
vector<int> a;
vector<Node> tree;
Node merge(Node left, Node right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.pref = max(left.pref, left.sum + right.pref);
    res.suff = max(right.suff, right.sum + left.suff);
    res.maxSum = max({left.maxSum, right.maxSum, left.suff + right.pref});
    return res;
}
void build(int id, int l, int r) {
    if (l == r) {
        long long val = a[l];
        tree[id] = {val, max(0LL, val), max(0LL, val), max(0LL, val)};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
}
Node query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return {0, 0, 0, 0};
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    Node left = query(id * 2, l, mid, u, v);
    Node right = query(id * 2 + 1, mid + 1, r, u, v);
    return merge(left, right);
}
int main() {
    cin >> n >> q;
    a.resize(n + 1);
    tree.resize(4 * n);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r).maxSum << "\n";
    }
    return 0;
}

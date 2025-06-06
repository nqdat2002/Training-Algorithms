#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
vector<int> rightLevelOrder(Node* root) {
    vector<int> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node* node = q.front(); q.pop();
            res.push_back(node->val);
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
    }
    return res;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        Node* root = nullptr;
        for (int i = 0; i < n; ++i)
            root = insert(root, a[i]);
        vector<int> res = rightLevelOrder(root);
        for (int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
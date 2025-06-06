#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* buildTree(const vector<int>& v) {
    if (v.empty()) return NULL;
    int n = v.size();
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) nodes[i] = new Node(v[i]);
    
    for (int i = 0; i < n; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n) nodes[i]->left = nodes[left];
        if (right < n) nodes[i]->right = nodes[right];
    }
    return nodes[0];
}
void inorder(Node* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        Node* root = buildTree(a);
        vector<int> res;
        inorder(root, res);
        for (int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}

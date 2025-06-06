#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left, *right;
};

typedef Node* tree;

tree createNode(int val){
    tree res = new Node;
    res -> val = val;
    res -> left = res -> right = NULL;
    return res;
}

void bfs(tree T){
    queue<tree> q;
    stack<int> st;
    q.push(T);
    tree top;
    while(q.size()){
        top = q.front();
        q.pop();
        st.push(top -> val);
        if(top -> right)
            q.push(top -> right);
        if(top -> left)
            q.push(top -> left);
    }
    while(st.size()){
        cout << st.top() << ' ';
        st.pop();
    }
}

int main(){
    int t = 1, n, child, par;
    char c;
    cin >> t;
    while(t--){
        cin >> n;
        unordered_map<int, tree> m;
        cin >> par >> child >> c;
        tree T = createNode(par);
        if(c == 'L'){
            T -> left = createNode(child);
            m[child] = T -> left;
        }
        else{
            T -> right = createNode(child);
            m[child] = T -> right;
        }
        m[par] = T;
        --n;
        while(n--){
            cin >> par >> child >> c;
            if(c == 'L'){
                m[par] -> left = createNode(child);
                m[child] = m[par] -> left;
            }
            else{
                m[par] -> right = createNode(child);
                m[child] = m[par] -> right;
            }
        }
        bfs(T);
        cout << endl;
    }
    return 0;
}

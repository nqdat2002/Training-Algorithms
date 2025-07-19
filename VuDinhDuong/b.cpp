#include <bits/stdc++.h>
using namespace std;
void Try(string &y, vector<bool> &vs, string &a, set<int> &res) {
    if (y.size() == a.size()) {
        int d = stoi(y); 
        res.insert(d);   
        return;
    }
    for (int i = 0; i < (int)a.size(); ++i) {
        if (vs[i]) continue;
        if (i > 0 && a[i] == a[i - 1] && !vs[i - 1]) continue;
        vs[i] = true;
        y.push_back(a[i]);
        Try(y, vs, a, res);
        y.pop_back();
        vs[i] = false;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        string n; cin >> n;
        sort(n.begin(), n.end());
        set<int> res;
        vector<bool> vs(n.size(), false);
        string y;
        Try(y, vs, n, res);
        for (int x : res) cout << x << endl;
    }
    return 0;
}

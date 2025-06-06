#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> L(n), R(n);
    vector<int> res(n + 1, 0);
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && a[dq.back()] >= a[i]) 
            dq.pop_back();
        
        L[i] = dq.empty() ? 0 : dq.back() + 1;
        dq.push_back(i);
    }
    dq.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        R[i] = dq.empty() ? n : dq.back();
        dq.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        int len = R[i] - L[i];
        res[len] = max(res[len], a[i]);
    }
    for (int X = n - 1; X >= 1; --X) 
        res[X] = max(res[X], res[X + 1]);
    
    for (int X = 1; X <= n; ++X) cout << res[X] << " ";
    
    return 0;
}
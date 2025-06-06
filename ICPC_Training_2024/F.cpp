#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < 5; ++j) cin >> a[i][j];

    unordered_map<int, unordered_set<int>> ums;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 5; ++j) ums[a[i][j]].insert(i);
    

    ll cnt = (long long)n * (n - 1) / 2, res = 0;

    for (const auto& e : ums) {
        const auto& x = e.second;
        res += x.size() * (x.size() - 1) / 2;
    }

    cout << cnt - res << endl;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int > > v;
        for(int i = 0; i < n; ++i){
            int a, b; cin >> a >> b;
            v.push_back({a, b});
        }
        int res = 0;
        for(auto x: v) if (x.first > x.second) res ++;
        cout << res << endl;

    }
    return 0;
}

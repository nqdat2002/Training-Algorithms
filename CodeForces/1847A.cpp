#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for(auto &x: a) cin >> x;
        int sum = 0;
        vector<int> v;
        for(int i = 0; i < n - 1; ++i){
            v.push_back(abs(a[i] - a[i + 1]));
            sum += abs(a[i] - a[i + 1]);
        }

        sort(v.begin(), v.end());
        for(int i = 1; i < k; ++i){
            sum -= v.back();
            v.pop_back();
        }
        cout << sum << endl;
    }
    return 0;
}

// |x - y| + |y - z| =

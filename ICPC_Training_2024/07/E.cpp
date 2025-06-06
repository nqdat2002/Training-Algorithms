#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[]) {
    int n; cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        sort(s.begin(), s.end()); 
        cnt[s]++; 
    }
    ll res = 0;
    for (auto &x : cnt) {
        int s = x.second;
        if (s > 1) {
            res += (ll)s * (s - 1) / 2;
        }
    }
    cout << res << endl;
    return 0;
}
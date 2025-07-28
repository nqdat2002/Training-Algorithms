#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_map<ll, int> freq;
    ll pref = 0, cnt = 0;
    freq[0] = 1;
    for (int i = 0; i < n; ++i) {
        pref += a[i];
        if (freq.find(pref) != freq.end()) {
            cnt += freq[pref];
        }
        freq[pref]++;
    }
    cout << cnt << endl;
}

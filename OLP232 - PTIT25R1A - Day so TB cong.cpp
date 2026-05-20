#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool check(ll T, const vector<ll>& A) {
    int n = A.size();
    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            long long current_sum = A[i] + A[l] + A[r];
            if (current_sum == T) {
                return true; 
            }
            if (current_sum < T) {
                l++; 
            } else {
                r--; 
            }
        }
    }
    return false;
}
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    map<ll, int> freq; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for (pair<ll, int> p : freq) {
        ll val = p.first;
        int count = p.second;
        ll target = 3 * val;
        if (check(target, a)) {
            cnt += count; 
        }
    }
    cout << cnt << "\n";
    return 0;
}
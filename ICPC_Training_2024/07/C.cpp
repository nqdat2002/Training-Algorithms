#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[]) {
    int n; cin >> n;
    vector<int> p(n);
    for (auto &x: p) cin >> x;
    int min_value = INT_MAX, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] <= min_value) {
            cnt++;
            min_value = p[i];
        }
    }
    cout << cnt << endl;
    return 0;
}
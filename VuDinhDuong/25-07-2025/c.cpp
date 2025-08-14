#include <bits/stdc++.h>
using namespace std;
int a[12], vs[12], s[4], total = 0;
int Try(int g, int ind, int sum, int pre) {
    int ans = 100000000;
    if (g == 3) {
        s[3] = total - s[0] - s[1] - s[2];
        int MAX = *max_element(s, s + 4);
        int MIN = *min_element(s, s + 4);
        return min(ans, MAX - MIN);
    }
    for (int i = pre; i < 12; ++i) {
        if (vs[i]) {
            vs[i] = 0;
            if (ind == 2) {
                s[g] = sum + a[i];
                ans = min(ans, Try(g + 1, 0, 0, 0));
            } else {
                ans = min(ans, Try(g, ind + 1, sum + a[i], i + 1));
            }
            vs[i] = 1;
        }
    }
    return ans;
}

int main() {
    for (int i = 0; i < 12; ++i) {
        cin >> a[i];
        total += a[i];
        vs[i] = 1;
    }
    int res = Try(0, 0, 0, 0);
    cout << res << endl;
}
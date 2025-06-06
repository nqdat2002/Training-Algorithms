#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[42][42];
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        string a = s;
        reverse(a.begin(), a.end());
        int n = s.length();
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= n; ++i) f[i][i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == a[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[n][n] << endl;
    }
    return 0;
}
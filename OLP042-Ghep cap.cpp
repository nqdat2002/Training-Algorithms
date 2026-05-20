#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<bool> a(1e6 + 5, 1);
vector<int> e;
void era() {
    for (int i = 2; i <= 1000000; i++) {
        if (a[i]) {
            e.push_back(i);
            for (int j = i * i; j <= 1000000; j += i)a[j] = 0;
        }
    }
}
main() {
    era();
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        int ans = 1;
        for (int i = 0; i < (int)e.size(); i++) {
            if (e[i]*e[i] > n)break;
            if (a[e[i]] && n % e[i] == 0) {
                int s = 0;
                while (n % e[i] == 0) {
                    s++;
                    n /= e[i];
                }
                ans *= s + 1;
            }
        }
        if (n > 1) ans *= 2;
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;

int c[200000];
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> c[i];

        int allneg = 1;
        for (int i = 0; i < n; i++) allneg &= (c[i] < 0);
        if (allneg) printf("%d\n", *max_element(c, c + n));
        else {
            LLI ans1 = 0, ans2 = 0;
            for (int i = 0; i < n; i++) {
                if (i & 1) ans1 += max(c[i], 0);
                else ans2 += max(c[i], 0);
            }
            printf("%lld\n", max(ans1, ans2));
        }
    }
    return 0;
}
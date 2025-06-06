#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        int l = (1 << n) - 1, cnt = 0;
        for (int x = 0; x <= l; x++) {
            string tmp = "";
            for (int i = 1; i <= n; i++) {
                if (x >> (i - 1) & 1) tmp += '1';
                else tmp += '0';
            }
            reverse(tmp.begin(), tmp.end());
            if (tmp.find(s) != -1) ++cnt;
        }
        cout << cnt << endl;
    }
}
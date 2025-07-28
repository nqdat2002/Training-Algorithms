#include <bits/stdc++.h>
using namespace std;
bool check(const string& s, int l, int r) {
    l--; r--;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    string s; int M;
    cin >> s >> M;
    for (int i = 0; i < M; ++i) {
        int l, r; cin >> l >> r;
        if (check(s, l, r)) cout << "YES\n";
        else cout << "NO\n"; 
    }
}

#include <bits/stdc++.h>

using namespace std;
int main() {
    set<string> perms;
    string s; cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    perms.insert(s);
    while (next_permutation(s.begin(), s.end()))
        perms.insert(string(s.begin(), s.end()));

    cout << perms.size() << '\n';
    for (string perm : perms)
        cout << perm << '\n';
}
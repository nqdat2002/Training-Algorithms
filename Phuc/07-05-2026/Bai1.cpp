#include<bits/stdc++.h>
using namespace std;
bool check(string s) {
    if (s.size() != 10) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    string pref = s.substr(0, 2);
    if (pref == "03" || pref == "05" || pref == "07" || pref == "08" || pref == "09") {
        return true;
    }
    return false;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (check(s)) cout << "Yes" << endl;
        else cout << "No" << endl;    
    }
}
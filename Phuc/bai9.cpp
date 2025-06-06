#include <bits/stdc++.h>
using namespace std;
int getRes(string s) {
    int cnt = 0, res = 0;
    for (char c : s) {
        if (c == '(') {
            cnt++;
            res = max(res, cnt);
        } else if (c == ')') {
            cnt--;
            if (cnt < 0) return -1; 
        }
    }
    return (cnt == 0) ? res : -1; 
}
int main() {
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	cout << getRes(s) << endl;
    }
}

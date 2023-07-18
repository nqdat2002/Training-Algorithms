#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
bool checkMaxtrix(char a[][3], char c){
    return 
        (a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][0] == c)
        || (a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][0] == c) 
        || (a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][0] == c) 
        || (a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[0][0] == c)
        || (a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[0][1] == c) 
        || (a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[0][2] == c)
        || (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == c) 
        || (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] == c);
}

string check(char a[][3]){
    if(checkMaxtrix(a, 'X')) return "X";
    if(checkMaxtrix(a, 'O')) return "O";
    if(checkMaxtrix(a, '+')) return "+";
    return "DRAW";
}
int main() {
    int t; cin >> t;
    while (t--) {
        char a[3][3];
        for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) cin >> a[i][j];
        cout << check(a) << endl;

    }
    return 0;
}

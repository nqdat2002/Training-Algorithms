#include <bits/stdc++.h>
using namespace std;
int main() {
    int s1, f1, s2, f2;
    cin >> s1 >> f1 >> s2 >> f2;
    cout << max(abs(s2 - s1), abs(f2 - f1)) << endl;
}

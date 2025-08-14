#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}
int main() {
    string s; cin >> s;
    int sum = 0;
    bool chan = false, le = false;
    for (char ch : s) {
        int digit = ch - '0';
        sum += digit;
        if (digit % 2 == 0) chan = true;
        else le = true;
    }
    if (isPrime(sum) && chan && le) cout << "YES" << endl;
    else cout << "NO" << endl;
}
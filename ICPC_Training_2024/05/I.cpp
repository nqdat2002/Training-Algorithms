#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    int count_plus = 0, count_minus = 0;

    for (char c : s) {
        if (c == '+') {
            count_plus++;
        } else if (c == '-') {
            count_minus++;
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        long long a, b;
        cin >> a >> b;

        long long gcd_ab = __gcd(a, b);

        // Điều kiện kiểm tra: (count_plus * b - count_minus * a) % gcd_ab == 0
        if ((count_minus * b - count_plus * a) % (a + b) == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

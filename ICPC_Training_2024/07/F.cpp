#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll find_fib(ll n) {
    int t_0 = 0, t_1 = 1, t_2;
    for (int i = 2; ; i++) {
        t_2 = (t_0 + t_1) % n;
        t_0 = t_1;
        t_1 = t_2;
        if (t_0 == 0 && t_1 == 1) {
            return i - 1;
        }
    }
}

int main(int argc, char const *argv[]){
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << find_fib(n) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int const mod = 1e9 + 7;

ll fibo[93];

void fill() {
    fibo[0] = 1;
    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i < 93; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
}

ll find(ll n, ll k) {
    if (n == 0) 
        return 1;
    if(n == 1)
        return 0;
    if (k <= fibo[n - 1])
        return find(n - 1, k);
    return find(n - 2, k - fibo[n - 1]) + find(n - 1, k);
}

int main() {
    fast_io;
    fill();
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        cout << find(n, k) << endl;
    }
    return 0;
}

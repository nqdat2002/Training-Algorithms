#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll pow10(int x){
    ll res = 1;
    for(int i = 0; i < x; i++)
        res *= 10;
    return res;
}

int solve(ll n){
    if(n < 9) return (int) n + 1;
    int len = 1;
    while(9 * pow10(len - 1) * len < n){
        n -= 9 * pow10(len - 1) * len;
        len++;
    }
    string s = to_string(pow10(len - 1) + n / len);
    return (int) (s[n % len] - '0');
}

int main(){
    int q; cin >> q;
    while(q --){
        ll k; cin >> k;
        cout << solve(k - 1) << endl;
    }
}
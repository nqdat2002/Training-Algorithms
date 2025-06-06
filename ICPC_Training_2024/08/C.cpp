#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll factorial(int n) {
    ll res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

ll findNext(vector<int> a) {
    int n = a.size();
    ll index = 0;
    vector<bool> vs(n + 1, false);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 1; j < a[i]; ++j) {
            if (!vs[j]) cnt++;
        }
        index += cnt * factorial(n - 1 - i);
        vs[a[i]] = true;
    }
    return index + 1;
}
vector<int> findPer(int n, ll X) {
    vector<int> res, a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;
    X--;
    for (int i = n; i >= 1; --i) {
        ll fact = factorial(i - 1);
        int index = X / fact;
        res.push_back(a[index]);
        a.erase(a.begin() + index);
        X %= fact;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, type;
        cin >> n >> type;
        if (type == 1) {
            vector<int> P(n);
            for (auto &x: P) cin >> x; 
            cout << findNext(P);
        } else if (type == 2) {
            ll x; cin >> x;
            vector<int> a = findPer(n, x);
            for (int i = 0; i < n; ++i) 
                cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

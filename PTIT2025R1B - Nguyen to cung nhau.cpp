#include <bits/stdc++.h>
using namespace std;
const int MAXA = 100000;
int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> spf(MAXA + 1);
    for (int i = 1; i <= MAXA; i++) spf[i] = i;

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    set<int> bad;
    for (int x : A) {
        while (x > 1) {
            int p = spf[x];
            bad.insert(p);
            while (x % p == 0) x /= p;
        }
    }
    vector<bool> ok(M + 1, true);
    ok[0] = false;
    for (int p : bad) 
        for (int j = p; j <= M; j += p) 
            ok[j] = false;
        
    vector<int> res;
    for (int k = 1; k <= M; k++) if (ok[k]) res.push_back(k);
    cout << res.size() << '\n';
    for (int x : res) cout << x << " ";
}


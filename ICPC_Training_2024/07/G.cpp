#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
bool cmp(double a, double b) {
    return fabs(a - b) < EPS;
}
int main(int argc, char const *argv[]) {
    int n; cin >> n;
    set<double> res;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        int Ai, Bi, Ci;
        cin >> Ai >> Bi >> Ci;
        if (Ai == 0) {
            if (Bi == 0) {
                if (Ci == 0) {
                    ok = true;
                }
                else continue;
            }
            else {
                res.insert(-static_cast<double>(Ci) / Bi);
            }
        }
        else {
            ll delta = 1LL * Bi * Bi - 4LL * Ai * Ci;

            if (delta > 0) {
                double sqrt_delta = sqrt(delta);
                double x1 = (-Bi + sqrt_delta) / (2.0 * Ai);
                double x2 = (-Bi - sqrt_delta) / (2.0 * Ai);
                res.insert(x1);
                res.insert(x2);
                // res.insert(static_cast<double>(-Bi + sqrt(delta)) / (2.0 * Ai));
                // res.insert(static_cast<double>(-Bi - sqrt(delta)) / (2.0 * Ai));
            } else if (delta == 0) {
                double x = -static_cast<double>(Bi) / (2.0 * Ai);
                res.insert(x);
            }
        }
    }
    if (ok) cout << -1 << endl;
    else {
        map<double, bool> unq;
        for (const double &x : res) {
            bool unique = true;
            for (const auto &entry : unq) {
                if (cmp(x, entry.first)) {
                    unique = false;
                    break;
                }
            }
            if (unique) unq[x] = true;
        }
        cout << unq.size() << endl;
    }
    return 0;
}

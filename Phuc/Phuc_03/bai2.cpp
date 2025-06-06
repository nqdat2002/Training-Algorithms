#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
struct Subset {
    vector<int> idx; int sum;
    bool operator < (const Subset &o) const {
        if (sum != o.sum) return sum < o.sum;
        return idx < o.idx;
    }
};
void Try(vector<Subset> &res) {
    int x = 1 << n;
    for (int mask = 1; mask < x; ++mask) {
        vector<int> idx;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                idx.push_back(i + 1);
                sum += a[i];
            }
        }
        if (sum <= k) res.push_back({idx, sum});
    }
}
int main() {
    cin >> n >> k; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<Subset> res;
    Try(res);
    if (res.empty()) {
        cout << -1 << endl;
        return 0;
    }
    sort(res.begin(), res.end());
    for (auto &s : res) {
        for (int idx : s.idx) cout << idx << " ";
        cout << "\n" << "Sum = " << s.sum << endl;
    }
}




















































// #include <bits/stdc++.h>
// using namespace std;
// int n, k;
// vector<int> a, sum;
// bool ok = false;
// void Try(int i, int S) {
//     if (S > k) return;
//     if (!sum.empty()) {
//         ok = true;
//         for (int x : sum)
//             cout << x + 1 << " ";
//         cout << endl;
//         cout << "Sum = " << S << endl;
//     }
//     for (int j = i; j < n; ++j) {
//         sum.push_back(j);
//         Try(j + 1, S + a[j]);
//         sum.pop_back();
//     }
// }

// int main() {
//     cin >> n >> k;
//     a.resize(n);
//     sum.clear();
//     for (int i = 0; i < n; ++i) cin >> a[i];
//     Try(0, 0);
//     if (!ok) cout << -1 << endl;
// }

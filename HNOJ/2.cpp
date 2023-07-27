#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void HN(int n, int s, int t) {
    if (n <= 0) return;
    if (n == 1) {
        string tmp = "";
        tmp += char(s + 64);
        tmp += char(t + 64);
        v.push_back(tmp);
        v.push_back(tmp);
        return;
    }
    HN(n - 1, s, 6 - s - t);
    HN(1, s, t);
    HN(n - 1, 6 - s - t, t);
}
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    v.clear();
    HN(n / 2, 1, 3);
    cout << v.size() << endl;
    for (auto x : v) cout << x << endl;
    return 0;
}

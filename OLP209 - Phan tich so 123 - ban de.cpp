#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
vector<int> good;
int dp[MAXN + 1];

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x > MAXN) continue;
        good.push_back(x);

        q.push(x * 10 + 1);
        q.push(x * 10 + 2);
        q.push(x * 10 + 3);
    }
    for (int i = 0; i <= MAXN; i++) dp[i] = 1e9;
    dp[0] = 0;
    for (int val : good) {
        for (int i = val; i <= MAXN; i++) {
            dp[i] = min(dp[i], dp[i - val] + 1);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
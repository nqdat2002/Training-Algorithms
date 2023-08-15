#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minLength(string x, string y) {
    int m = x.length();
    int n = y.length();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) 
                dp[i][j] = i + j;
            else if (x[i - 1] == y[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
        }
    }
    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string x, y;
    cin >> x >> y;
    cout << minLength(x, y) << endl;

    return 0;
}

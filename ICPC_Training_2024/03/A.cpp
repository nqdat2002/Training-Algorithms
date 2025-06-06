#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double distanceSquared(const Point& a, const Point& b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Point> A(N);
    vector<Point> B(M);

    for (int i = 0; i < N; ++i) {
        cin >> A[i].x >> A[i].y;
    }

    for (int j = 0; j < M; ++j) {
        cin >> B[j].x >> B[j].y;
    }

    vector<vector<double>> dist(N + M, vector<double>(N + M, numeric_limits<double>::infinity()));

    // Calculate distances within the same area
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            dist[i][j] = dist[j][i] = distanceSquared(A[i], A[j]);
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M; ++j) {
            dist[N + i][N + j] = dist[N + j][N + i] = distanceSquared(B[i], B[j]);
        }
    }

    // Calculate distances between different areas
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dist[i][N + j] = dist[N + j][i] = distanceSquared(A[i], B[j]);
        }
    }

    vector<double> dp(N + M, numeric_limits<double>::infinity());
    dp[0] = 0; // Start from the first location in area A

    // Dynamic Programming to find the minimum energy consumption
    for (int _ = 0; _ < N + M; ++_) {
        for (int u = 0; u < N + M; ++u) {
            for (int v = 0; v < N + M; ++v) {
                if (dp[u] + dist[u][v] < dp[v]) {
                    dp[v] = dp[u] + dist[u][v];
                }
            }
        }
    }

    // The result is the minimum energy consumption to reach the last location in area A
    cout << dp[N - 1] << endl;

    return 0;
}

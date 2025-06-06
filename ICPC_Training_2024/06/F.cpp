#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    int x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool isPossible(const vector<Point>& points, double d) {
    int n = points.size();
    vector<bool> vs(n, false);
    queue<int> q;

    vs[0] = true;
    q.push(0);

    int cnt = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!vs[v] && distance(points[u], points[v]) <= d) {
                vs[v] = true;
                q.push(v);
                ++cnt;
            }
        }
    }

    return cnt == n;
}

double find_minimum_d(const vector<Point>& points) {
    double l = 0, r = 2e9;
    while (r - l > 1e-7) {
        int m = (l + r) / 2;
        if (isPossible(points, m))
            r = m;
        else
            l = m;

    }
    return r;
}

int main(int argc, char const *argv[]) {
    int n; cin >> n;
    vector<Point> points(n + 1);
    points[0] = {0, 0};
    for (int i = 1; i <= n; ++i) cin >> points[i].x >> points[i].y;
    double res = find_minimum_d(points);
    cout << fixed << setprecision(6) << res << endl;

}

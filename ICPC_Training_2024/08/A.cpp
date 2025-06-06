#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
struct Point {
    double x, y;
};

struct Circle {
    Point c;
    double r;
};

double dist(const Point &a, const Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

Circle twoPoints(const Point &a, const Point &b) {
    Point c = {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
    double r = dist(a, b) / 2.0;
    return {c, r};
}

Circle threePoints(const Point &a, const Point &b, const Point &c) {
    double d = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    if (abs(d) < EPS) return {{0, 0}, 0};
    double ux = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / d;
    double uy = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / d;
    Point circle = {ux, uy};
    double r = dist(circle, a);
    return {circle, r};
}
bool isInside(const Circle &circle, const Point &point) {
    return dist(circle.c, point) <= circle.r + EPS;
}

Circle welzl(vector<Point> &points, vector<Point> boud, int n) {
    if (n == 0 || boud.size() == 3) {
        if (boud.size() == 0)
            return {{0, 0}, 0};
        else if (boud.size() == 1)
            return {boud[0], 0};
        else if (boud.size() == 2)
            return twoPoints(boud[0], boud[1]);
        else
            return threePoints(boud[0], boud[1], boud[2]);
    }
    Point p = points[n - 1];
    Circle c = welzl(points, boud, n - 1);
    if (isInside(c, p)) return c;
    boud.push_back(p);
    return welzl(points, boud, n - 1);
}
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) cin >> points[i].x >> points[i].y;
    Circle ans = welzl(points, {}, points.size());
    cout << fixed << setprecision(6) << ans.r << endl;

    return 0;
}

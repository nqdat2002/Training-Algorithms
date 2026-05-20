#include<bits/stdc++.h>
using namespace std;
class Point {
public:
    long long x, y, z;
    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y >> p.z;
        return is;
    }
    double operator-(const Point& other) const {
        return (double)(abs(x - other.x) + abs(y - other.y) + abs(z - other.z));
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        Point A;
        Point B;
        cin >> A >> B;
        cout << setprecision(2) << fixed << (A - B) << endl;
    }
    return 0;
}
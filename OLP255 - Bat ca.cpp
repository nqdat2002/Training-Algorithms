#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Fish {
    ll w;
    double x, v;
};
struct Event {
    double t;
    int type; 
    ll w;
    bool operator<(const Event& other) const {
        if (abs(t - other.t) > 1e-9) return t < other.t;
        return type > other.type;
    }
};

int main() {
    int n;
    double a;
    cin >> n >> a;
    vector<Fish> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i].w >> f[i].x >> f[i].v;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<Event> ev;
        ll cur = 0;

        for (int j = 0; j < n; ++j) {
            double dx = f[j].x - f[i].x;
            double dv = f[j].v - f[i].v;
            if (dv == 0) {
                if (dx >= 0 && dx <= a) cur += f[j].w;
            } else if (dv > 0) {
                double t1 = -dx / dv;
                double t2 = (a - dx) / dv;
                if (t2 >= 0) {
                    t1 = max(0.0, t1);
                    ev.push_back({t1, 1, f[j].w});
                    ev.push_back({t2, -1, f[j].w});
                }
            } else { // dv < 0
                double t1 = (a - dx) / dv;
                double t2 = -dx / dv;
                if (t2 >= 0) {
                    t1 = max(0.0, t1);
                    ev.push_back({t1, 1, f[j].w});
                    ev.push_back({t2, -1, f[j].w});
                }
            }
        }

        sort(ev.begin(), ev.end());
        ans = max(ans, cur);
        for (auto& e : ev) {
            cur += e.type * e.w;
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
int n, k, a[100005], cnt = 0, mi;

void init() {
    cnt = 0;
    mi = 100000000;
    cin >> n >> k;
    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
        if (a[i] < 0) cnt++;
        mi = min(mi, abs(a[i]));
    }
}

void process() {
    sort(a, a + n);
    ll ans = 0;
    if (k <= cnt) {
        for (int i = 0; i < k; i++) ans += abs(a[i]);
        for (int i = k; i < n; i++) ans += a[i];
    }
    else {
        for (int i = 0; i < n; i += 1) ans += abs(a[i]);
        k -= cnt;
        if (k % 2)
            ans -= 2*mi;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    process();
    return 0;
}
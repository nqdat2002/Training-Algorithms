#include <bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define All(v) (v).begin(),(v).end()
#define reset(x) memset((x),0,sizeof((x)))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        bool f = false;
        for(int i = 0; i < n; ++i){
            if(a[i] != b[i]){
                cout << 0 << endl;
                f = true;
                break;
            }
        }
        if(f) continue;
        int nmin = INT_MAX, index;
        for(int i = 0; i < n - 1; ++i){
            if(a[1 + i] - a[i] < nmin){
                nmin = a[1 + i] - a[i];
                index = i;
            }
        }
        int res = (a[index + 1] - a[index])/ 2 + 1;
        cout << res;
        cout << endl;
    }
    return 0;
}

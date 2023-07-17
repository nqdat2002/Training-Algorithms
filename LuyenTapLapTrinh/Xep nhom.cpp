#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_possible(vector<ll>& teams, ll T, ll k){
    ll sum = 0;
    for (int i = 0; i < teams.size(); i++) {
        sum += min(T, teams[i]);
    }
    return (sum >= (1ll * T * k));
}

ll countOfTeams(vector<ll>& teams_list, ll N, ll K){
    ll lb = 0, ub = 1e12;
    while (lb <= ub) {
        ll mid = lb + (ub - lb) / 2;
        if (is_possible(teams_list, mid, K)) {

            if (!is_possible(teams_list, mid + 1, K)) {
                return mid;
            }
            else {
                lb = mid + 1;
            }
        }
        else {
            ub = mid - 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &x: arr) cin >> x;
        cout << countOfTeams(arr, n, k) << endl;
    }

    return 0;
}

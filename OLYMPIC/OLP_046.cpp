#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll Area(ll a[], int n){
	ll res = LLONG_MIN;
	int i;
	stack<ll> st;
	while(i < n){
		if(st.empty() || a[i] >= a[st.top()]){
			st.push(i);
			i ++;
		}else{
			ll j = st.top();
			st.pop();
			if(st.empty()) res = max(res, i * a[j]);
			else res = max(res, (i - st.top() - 1) * a[j]);
		}
	}
	while(st.size()){
		ll j = st.top();
		st.pop();
		if(st.empty()) res = max(res, i * a[j]);
		else res = max(res, (i - st.top() - 1) * a[j]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll a[n];
		for(auto &x: a) cin >> x;
		cout << Area(a, n) << endl;
	}
	return 0;
}

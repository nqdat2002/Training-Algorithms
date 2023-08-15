// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double ld;
// typedef pair<int, int> p;
// typedef vector<vector<int> > vt;
// typedef vector<pair<int, int> > vp;
// const ll mod = 1e9 + 7;
// const int oo = 1e6 + 7;

// #define f first
// #define s second
// #define pb push_back
// #define ep emplace_back
// #define sz(a) (int) a.size()
// #define ms(s, n) memset(s, n, sizeof(s))
// #define present(t, x) (t.find(x) != t.end())
// #define all(a) (a.begin(), a.end())
// #define For(i, l, r) for (int i = l; i <= r; i++)
// #define Fod(i, r, l) for (int i = r; i >= l; i--)
// #define fillchar(a, x) memset(a, x, sizeof (a))
// #define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// void FileIO() {
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// }

// int main(int argc, char const *argv[]) {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int n;
// 	cin >> n;
// 	ll a[n], pref[n], dp[n], dp2[n], dpMax[n];

// 	for (auto &x : a) cin >> x;
// 	for (int i = 2; i < n; ++i)
// 		pref[i] = a[i] + a[i - 1] + a[i - 2];

// 	dp[2] = pref[2];
// 	for (int i = 3; i < n; ++i)
// 		dp[i] = max(pref[i], dp[i - 3] + pref[i]);

// 	dp2[n - 3] = pref[n - 1];
// 	for (int i = n - 4; i >= 0; --i)
// 		dp2[i] = max(pref[i + 2], dp2[i + 3] + pref[i + 2]);

// 	dpMax[2] = dp[2];
// 	for(int i = 3; i < n; ++i){
// 		dpMax[i] = max(dpMax[i - 1], dp[i]);
// 	}
// 	ll res = -1e18;

// 	for(int i = 3; i < n - 2; ++i){
// 		res = max(res, dp2[i] + dpMax[i - 1]);
// 	}
// 	cout << res << endl;

// 	return 0;
// }
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define DOWN(i,a,b) for(int i=a; i>=b; i--)

typedef long long LL;



int main()
{
	int n;
	LL MAX = -9999999999;
	
	vector<LL> a,t3,T1,T2,T1MAX;
		
	cin>>n;	
	
	
	a.resize(n);
	FOR(i,0,n-1)
		cin>>a[i];
	
	t3.resize(n);
	FOR(i,2,n-1)
		t3[i] = a[i] + a[i-1] + a[i-2];
	
	T1.resize(n);
	T1[2] = t3[2];
	FOR(i,3,n-1)
		T1[i] = max(t3[i], T1[i-3] + t3[i]);	
	
	T2.resize(n);
	T2[n-3] = t3[n-1];// = a[n-3] + a[n-2] + a[n-1];
	DOWN(i,n-4,0)
		T2[i] = max(t3[i+2], T2[i+3] + t3[i+2]);
	
	T1MAX.resize(n);
	T1MAX[2] = T1[2];
	FOR(i,3,n-1)
		T1MAX[i] = max(T1MAX[i-1],T1[i]);
	
	FOR(j,3,n-3)
		MAX = max(MAX,T2[j] + T1MAX[j-1]);
	
	cout<<MAX<<endl;
	
	return 0;
}
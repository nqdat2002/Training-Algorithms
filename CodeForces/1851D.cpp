#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll a[n - 1];
		set<ll> s;
		s.insert(n);
		for(int i = 0; i < n - 1; ++i){
			cin >> a[i];
			s.insert(i + 1);
		}
		ll l = -1, f = 1;
		if(s.find(a[0]) != s.end()){
			s.erase(s.find(a[0]));
		}else{
			if(l == -1) l = a[0];
			else f = 0;
		}
		for(int i = 1; i < n - 1; ++i){
			ll dist = a[i] - a[i - 1];
			if(s.find(dist) != s.end()){
				s.erase(s.find(dist));
			}else{
				if(l == -1) l = dist;
				else{
					f = 0;
					break;
				}
			}
		}

		if(f == 0){
			cout << "NO";
		}else{
			ll res = 0;
			for(auto x: s) res += x;
			if(l == -1){
				ll maxsum = n * (n + 1) / 2;
				if(maxsum - a[n - 2] == res){
					cout << "YES";
				}
				else cout << "NO";
			}else{
				if(res == l){
					cout << "YES";
				}
				else cout << "NO";
			}
		}
		cout << endl;
	}
	return 0;
}
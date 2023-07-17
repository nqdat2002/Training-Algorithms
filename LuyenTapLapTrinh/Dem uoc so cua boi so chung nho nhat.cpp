#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 100005;
const int mod = 1e9 + 7;
bool prime[nmax];
void Prime() {
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= nmax - 5; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= nmax - 5; i += p)
                prime[i] = false;
        }
    }
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	Prime();
	while(t--){
		int n; cin >> n;
		vector<int> v;
		for (int i = 2; i <= n; ++i){
			if(prime[i]){
				cout << i << endl;
				v.push_back(i);
			}
		}
		ll res = 1;
		for(auto x: v){
			res = res * (1 + 1) % mod;
		}
		cout << res % mod << endl;
	}
	return 0;
}
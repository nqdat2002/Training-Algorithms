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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
const int N = 1e6 + 400000;
bool isPrime[N+1];
vector<int> sieve(int N) {

    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
    vector<int> v;
    for (int i = 0; i < N; ++i) if(isPrime[i]) v.push_back(i);
    return v;
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// FileIO();
	vector<int> v = sieve(N);
	int H, L;
	string p;
	cin >> H >> L >> p;
	int cnt = 0;
	for (int i = H - 1; i < L; ++i){
		string ss = to_string(v[i]);
		if(ss.find(p) != string::npos) cnt ++;
	}
	cout << cnt << endl;
	return 0;
}
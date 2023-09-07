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

const int MAXW = 1e6 + 1;

struct DSU {
    vector<int> pset;
    vector<pair<int, int> > records;
    bool recording;

    DSU(int n) {
        pset.resize(n+1);
        for(int i = 1; i <= n; ++i) pset[i] = i;
        recording = false;
    }

    void setRecording(bool mode) {
        recording = mode;
    }

    void modifyPset(int u, int x) {
        if (recording) records.push_back({u, pset[u]});
        pset[u] = x;
    }

    int findSet(int i) {
        if (pset[i] == i) return i;
        modifyPset(i, findSet(pset[i]));
        return pset[i];
    }

    bool unionSet(int u, int v) {
        u = findSet(u); v = findSet(v);
        if (u == v) return false;
        modifyPset(u, v);
        return true;
    }

    void rollback() {
        while (!records.empty()) {
            pair<int, int> pp = records.back();
            records.pop_back();
            pset[pp.first] = pp.second;
        }
    }
};

int n, m;
vector<pair<int, int> > adj[MAXW];

int main(int argc, char const *argv[]){
    // FileIO();
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[w].push_back({u, v});
    }

    DSU s(n);
    ll sumW = 0, cnt = 1; 
    for(int w = 1; w < MAXW; ++w) {
        int k = adj[w].size(), maxE = 0, cntMask = 1;
        for(int mask = 1; mask < (1<<k); ++mask) {
            s.setRecording(true);
            bool ok = true;
            for(int i = 0; i < k; ++i) {
                if ((mask>>i)&1) {
                    pair<int, int > pp = adj[w][i];
                    if (!s.unionSet(pp.first, pp.second)) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                int cntE = __builtin_popcount(mask);
                if (cntE > maxE) {
                    maxE = cntE;
                    cntMask = 1;
                } else if (cntE == maxE) {
                    ++cntMask;
                }

            }
            s.rollback();
        }

        s.setRecording(false);
        for(pair<int, int> pp: adj[w]) {
            s.unionSet(pp.first, pp.second);
        }

        sumW += 1LL * w * maxE;
        cnt = (cnt * cntMask) % mod;
    }

    cout << sumW << " " << cnt << endl;
    return 0;
}

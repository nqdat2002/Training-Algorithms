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

void build(const vector<int>& a, vector<int>& tree, int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(a, tree, 2 * id + 1, l, m);
    build(a, tree, 2 * id + 2, m + 1, r);

    vector<int> temp(r - l + 1);
    merge(tree.begin() + 2 * id + 1, tree.begin() + 2 * id + 1 + (m - l + 1),
          tree.begin() + 2 * id + 2, tree.begin() + 2 * id + 2 + (r - m), temp.begin());
    copy(temp.begin(), temp.end(), tree.begin() + 2 * id + 1);
}

void update_sort(vector<int>& tree, int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        sort(tree.begin() + id, tree.begin() + id + (r - l + 1));
        return;
    }

    int m = (l + r) >> 1;
    if (L <= m) {
        update_sort(tree, 2 * id + 1, l, m, L, R);
    }
    if (R > m) {
        update_sort(tree, 2 * id + 2, m + 1, r, L, R);
    }

    vector<int> temp(r - l + 1);
    merge(tree.begin() + 2 * id + 1, tree.begin() + 2 * id + 1 + (m - l + 1),
          tree.begin() + 2 * id + 2, tree.begin() + 2 * id + 2 + (r - m), temp.begin());
    copy(temp.begin(), temp.end(), tree.begin() + 2 * id + 1);
}

vector<int> query(vector<int>& tree, int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        vector<int> subarray(tree.begin() + id, tree.begin() + id + (r - l + 1));
        sort(subarray.begin(), subarray.end());
        return subarray;
    }

    int m = (l + r) >> 1;
    if (R <= m) {
        return query(tree, 2 * id + 1, l, m, L, R);
    }
    if (L > m) {
        return query(tree, 2 * id + 2, m + 1, r, L, R);
    }

    vector<int> lSubarray = query(tree, 2 * id + 1, l, m, L, m);
    vector<int> rSubarray = query(tree, 2 * id + 2, m + 1, r, m + 1, R);

    vector<int> result;
    merge(lSubarray.begin(), lSubarray.end(), rSubarray.begin(), rSubarray.end(), back_inserter(result));
    return result;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;

        vector<int> lf(n), rg(n);
        lf[0] = -1;
        for (int i = 0; i < n; ++i) {
            if (i > 0) lf[i] = lf[i - 1];
            if (s[i] == '0') lf[i] = i;
        }
        rg[n - 1] = n;
        for (int i = n - 1; i >= 0; --i) {
            if (i + 1 < n) rg[i] = rg[i + 1];
            if (s[i] == '1') rg[i] = i;
        }

        set<pair<int, int>> st;
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            int ll = rg[l - 1], rr = lf[r - 1];
            if (ll > rr) {
                st.insert({ -1, -1});
            } else {
                st.insert({ll, rr});
            }
        }

        cout << st.size() << endl;
    }
    return 0;
}
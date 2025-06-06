#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query {
    int left, right, index;
};

bool cmp(query a, query b) {
    int block_a = a.left / 700;  
    int block_b = b.left / 700;
    if (block_a != block_b) 
        return block_a < block_b;
    return (block_a & 1) ? (a.right < b.right) : (a.right > b.right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++)  cin >> a[i];
    vector<query> v(q);
    vector<int> ans(q), freq(n + 1, 0);

    for (int i = 0; i < q; i++) {
        cin >> v[i].left >> v[i].right;
        v[i].index = i;
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0, cur_left = 1, cur_right = 0;
    for (auto qq : v) {
        int L = qq.left, R = qq.right;
        while (cur_right < R) {
            cur_right++;
            freq[a[cur_right]]++;
            if (freq[a[cur_right]] == 1) cnt++;
        }
        while (cur_right > R) {
            if (freq[a[cur_right]] == 1) cnt--;
            freq[a[cur_right]]--;
            cur_right--;
        }
        while (cur_left > L) {
            cur_left--;
            freq[a[cur_left]]++;
            if (freq[a[cur_left]] == 1) cnt++;
        }
        while (cur_left < L) {
            if (freq[a[cur_left]] == 1) cnt--;
            freq[a[cur_left]]--;
            cur_left++;
        }
        ans[qq.index] = cnt;
    }
    for (int i = 0; i < q; i++) cout << ans[i] << endl;
    return 0;
}

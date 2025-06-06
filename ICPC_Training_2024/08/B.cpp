#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string getDec(ll p, ll q) {
    string res = to_string(p / q);
    p %= q; 
    if (p == 0) {
        return res; 
    }
    res += "."; 
    unordered_map<ll, int> remainderMap;
    string decp = ""; 
    while (p != 0) {
        if (remainderMap.find(p) != remainderMap.end()) {
            break;
        }
        remainderMap[p] = decp.size(); 
        p *= 10; 
        decp += to_string(p / q);
        p %= q;
    }

    res += decp;
    return res;
}
vector<int> computeLPS(const string &x) {
    int m = x.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (x[i] == x[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int findpos(const string &s, const string &x) {
    int n = s.size();
    int m = x.size();

    vector<int> lps = computeLPS(x);
    
    int i = 0;
    int j = 0;  
    while (i < n * 10) {
        if (s[i % n] == x[j]) {
            i++;
            j++;
        }
        
        if (j == m) {
            return (i - j) % n + 1; 
        } else if (i < n * 10 && s[i % n] != x[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return 0;
}
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll p, q;
    string x;
    cin >> p >> q >> x;
    string dec = getDec(p, q);
    dec.erase(remove(dec.begin(), dec.end(), '.'), dec.end());
    cout << findpos(dec, x) << endl;
    return 0;
}

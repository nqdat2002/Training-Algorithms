#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int Solve(string s, int k){
    int len = s.length();
    if(k > len)
        return 0;
    map<char, int> mp;
    for(int i = 0; i < len; i ++)
        mp[s[i]]++;
    priority_queue<int> q;
    for(int i = 'A'; i <= 'Z'; i ++)
        if(mp[i]) q.push(mp[i]);
    while(k--){
        int t = q.top(); q.pop();
        t--;
        q.push(t);
    }
    int res = 0;
    while(!q.empty()){
        int t = q.top(); q.pop();
        res += pow(t, 2);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string s; cin >> s;
        cout << Solve(s, k) << endl;
    }
    return 0;
}
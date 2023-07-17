#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m;
string s;
vector<int> v;
bool ok;

void init(){
    getline(cin , s); 
    v.clear();
    n = s.size(), m = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] == '?' && i != 3) 
            m++;
    }
    ok = false;
}

void Try(int i, vector<int> a, int cnt){
    if(ok) return;
    for(int j = 0; j <= 9; j ++){
        a.push_back(j);
        if(i == cnt){
            int index = 0;
            string res = s;
            for(int k = 0; k < n; k ++){
                if(k != 3 && res[k] == '?'){
                    res[k] = a[index] + 48;
                    index ++;
                }
            }
            int x = 10 * (res[0] - 48) + res[1] - 48;
            int y = 10 * (res[5] - 48) + res[6] - 48;
            int z = 10 * (res[10] - 48) + res[11] - 48;
            if(x >= 10 && y >= 10 && z >= 10){
                if(res[3] == '+'){
                    if(x + y == z){
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                }
                if(res[3] == '-'){
                    if(x - y == z){
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                }
                if(res[3] == '*'){
                    if(x * y == z){
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                }
                if(res[3] == '/'){
                    if(z * y == x){
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                }
                if(res[3] == '?'){
                    if(x + y == z){
                        res[3] = '+';
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                    if(x - y == z){
                        res[3] = '-';
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                    if(x * y == z){
                        res[3] = '*';
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                    if(y * z == x){
                        res[3] = '/';
                        cout << res << endl;
                        ok = true;
                        return;
                    }
                }
            }
        }
        else Try(i + 1, a, cnt);
        a.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    cin.ignore();
    while(t--){
        init();
        Try(0, v, m);
        if(!ok) cout << "WRONG PROBLEM!" << endl;
    }
    return 0;
}
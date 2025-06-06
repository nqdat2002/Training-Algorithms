#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() != c)
            st.pop();
        else 
            st.push(c); 
        
    }
    cout << s.size() - st.size() << endl;
    return 0;
}

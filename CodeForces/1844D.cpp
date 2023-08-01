#include <bits/stdc++.h>
using namespace std;

char s[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int c = 1;
        while ((n % c) == 0) c++;
        for (int i = 0; i < n; i++) s[i] = 'a' + (i % c);
        s[n] = '\0';
        printf("%s\n", s);
    }
    return 0;
}
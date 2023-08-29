#include <bits/stdc++.h>

using namespace std;
const int N = 8;

char c;
int ans;
bool b[N][N], a[N][N];

bool place(int x, int y) {
    bool yes = true;
    for (int i = 0; i < N; i++)
        if (b[x][i] || b[i][y])
            yes = false;
    for (int i = 0; x - i >= 0 && y - i >= 0; i++)
        if (b[x - i][y - i])
            yes = false;
    for (int i = 0; x - i >= 0 && y + i < N; i++)
        if (b[x - i][y + i])
            yes = false;
    return yes;
}

bool check() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (b[i][j] && a[i][j])
                return false;
    return true;
}

void dfs(int i) {
    if (i == N) {
        if (check())
            ans++;
        return;
    }
    for (int j = 0; j < N; j++) {
        if (place(i, j)) {
            b[i][j] = true;
            dfs(i + 1);
            b[i][j] = false;
        }
    }
}
int main(int argc, char const *argv[]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            a[i][j] = (c == '*');
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
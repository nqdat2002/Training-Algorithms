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

void FileIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

char info[5][5], coins_tmp[5][5];
int a[25], coins[5][5];
int res = 25;
int Change() {
    int k = 1;
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            coins[i][j] = a[k];
            if (a[k] == 1) 
				count++;
            k++;
        }
    }
    return count;
}
void Rotate() {
    for (int i = 1; i <= 4; i++) 
        for (int j = 1; j <= 4; j++)
            coins_tmp[i][j] = info[i][j];
    
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (coins[i][j] == 1) {
                if (coins_tmp[i][j] == 'b') coins_tmp[i][j] = 'w';
                else coins_tmp[i][j] = 'b';
                for (int k = 0; k < 4; k++) {
                    int X = i + dx[k];
                    int Y = j + dy[k];
                    if (X >= 1 && X <= 4 && Y >= 1 && Y <= 4) {
                        if (coins_tmp[X][Y] == 'b') coins_tmp[X][Y] = 'w';
                        else coins_tmp[X][Y] = 'b';
                    }
                }
            }
        }
    }
}

bool Check() {
    char init = coins_tmp[1][1];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (coins_tmp[i][j] != init) return false;
        }
    }
    return true;
}

void Next(int u) {
    if (u > 16) {
        int x = Change();
        Rotate();
        if (Check()) res = min(res, x);
    } else {
        a[u] = 0;
        Next(u + 1);
        a[u] = 1;
        Next(u + 1);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	cout.tie(NULL);
	
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            cin >> info[i][j];
    Next(1);
    if (res != 25) cout << res;
    else cout << "-1";
    return 0;
}

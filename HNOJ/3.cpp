#include<bits/stdc++.h>
#define ii pair <int,int>
using namespace std;
vector <ii> sol;
int g[4][4];

void hanoi(int n, int a, int b)
{
    if (n >= 1)
    {
        int c = 3 - a - b;
        if (g[a][b])
        {
            hanoi(n - 1, a, c);
            sol.push_back({a,b});
            hanoi(n - 1, c, b);
        }
        else
        {
            hanoi(n - 1,a,b);
            sol.push_back({a, c});
            hanoi(n - 1,b,a);
            sol.push_back({c, b});

            hanoi(n - 1,a,b);
        }
    }
}

int  main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> g[i][j];
    hanoi(n,0,2);
    cout << sol.size() << "\n";
    for (auto x: sol)
       cout << char('A' + x.first) << char('A' + x.second) << "\n";
}

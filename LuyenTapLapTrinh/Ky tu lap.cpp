#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int oo = 1e9;
int res, fopt, cnt;
int a[100];
int n;
vector<string> v;
bool visited[100];

int Count(string x, string y){
	int i = 0, j = 0, l1 = x.size(), l2 = y.size(), s = 0;
    while (i < l1 && j < l2){
        if (x[i] == y[j]){
            s ++;
            i ++;
            j ++;
        }
        while (x[i] < y[j]){
            i++;
            if (i == l1)
                break;
        }
        while (x[i] > y[j]){
            j++;
            if (j == l2)
                break;
        }
    }
    return s;
}

void init(){
	cin >> n;
	v.clear();
	v.resize(n + 1);
	v.push_back("");
	for(int i = 1; i <= n; i ++){
		cin >> v[i];
	}
	a[0] = 0;
	res = oo;
	memset(visited, false, sizeof(visited));
}

void Try(int i, int cnt){
	if(res < cnt)
		return;
	for(int j = 1; j <= n; j ++){
		if(!visited[j]){
			visited[j] = true;
			a[i] = j;
			if(i == n){
				res = min(res, cnt + Count(v[a[i - 1]], v[j]));
			}
			else if(res > cnt && i < n) 
				Try(i + 1, cnt + Count(v[a[i - 1]], v[j]));
			visited[j] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while(t--){

		init();
		Try(1, 0);
		cout << res << endl;
	}
	return 0;
}
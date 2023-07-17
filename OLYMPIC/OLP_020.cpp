#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dl[] = {1, 5, 2, 4, 6, 3};
const int dr[] = {4, 1, 3, 5, 2, 6};
string rotate(string s, const int a[], int n){
	string res = "";
	for(int i = 0; i < n; ++i){
		res += s[a[i] - 1];
	}
	return res;
}
void bfs(){
	string st = "", en = "";
	for(int i = 0; i < 6; ++i){
		char x; cin >> x; st += x;
	}
	for(int i = 0; i < 6; ++i){
		char x; cin >> x; en += x;
	}
	map<string, int> mp;
	mp.clear();
	queue<string> q;
	q.push(st);
	mp[st] = 1;
	while(q.size()){
		string cc = q.front(); q.pop();
		if(cc == en){
			cout << mp[cc] - 1 << endl;
			return;
		}
		
		string a = rotate(cc, dl, 6);
		if(!mp[a]){
			q.push(a);
			mp[a] = mp[cc] + 1;
		}
		string b = rotate(cc, dr, 6);
		if(!mp[b]){
			q.push(b);
			mp[b] = mp[cc] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--){
		bfs();
	}
	return 0;
}

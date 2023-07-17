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

bool visited[10005];
bool check[10005];
vector<int> adj[10005];
vector<int> readj[10005];
stack<int> st;
int n, m;
void dfs(int u){
	visited[u] = true;
	for(auto v: adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
	st.push(u);
}
void dfs2(int u){
	check[u] = true;
	for(auto v: readj[u]){
		if(!check[v])
			dfs2(v);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int t = 1;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < 10005; ++i) adj[i].clear();
		for(int i = 0; i < 10005; ++i) readj[i].clear();
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));
		for(int i = 1; i <= m; ++i){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			readj[v].push_back(u);
		}
		for(int u = 1; u <= n; ++u){
			if(!visited[u]){
				dfs(u);
			}
		}
		ll res = 0;
		while(!st.empty()){
			int u = st.top(); st.pop();
			if(!check[u]){
				++res;
				dfs2(u);
			}
			else if(!st.empty() && check[st.top()]) st.pop();
		}
		cout << res << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> v;
int a[15];
bool ok;
void next(){
	int i = k - 1;
	while(a[i] > a[i + 1] && i >= 1) --i;
	if(i == 0) ok = true;
	else{
		int j = k;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		
		for(int h = 0; h < n; ++h){
			swap(v[h][i - 1], v[h][j - 1]);
		}
		reverse(a + i + 1, a + k + 1);
		for(int h = 0; h < n; ++h){
			reverse(v[h].begin() + i, v[h].end());
		}
	}
}
int main(){

	v.clear();
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
	    string s; cin >> s;
	    v.push_back(s);
	}
	for(int i = 1; i <= k; ++i){
		a[i] = i;
	}
	ok = false;
	long long res = 1e12;
	
	while(!ok){
		vector<string> tmp = v;
		sort(tmp.begin(), tmp.end());
		res = min(res, stoll(tmp.back()) - stoll(tmp.front()));
		tmp.clear();
		next();
	}
//	do{
//		vector<string> tmp;
//		for(int i = 0; i < n; ++i){
//			string s = "";
//			for(int j = 1; j <= k; ++j){
//				s += v[i][a[j] - 1];
//			}
//			tmp.push_back(s);
//		}
//		v = tmp;
//		sort(tmp.begin(), tmp.end());
//		res = min(res, stoll(tmp.back()) - stoll(tmp.front()));
//		tmp.clear();
//	}while(next_permutation(a + 1, a + k + 1));
	cout << res << endl;
}

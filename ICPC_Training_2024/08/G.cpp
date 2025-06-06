#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int kmp[N];
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b; 
	cin >> a >> b;
	string s = b + '#' + a;
	kmp[0] = 0;
	for (int i = 1; i < (int)s.size(); ++i) {
		int j = kmp[i - 1];
		while (j > 0 && s[j] != s[i]) j = kmp[j - 1];
		if (s[j] == s[i]) ++j;
		kmp[i] = j;
	}

	for(int i = b.size() + 1; i < (int)s.size(); ++i){
		if (kmp[i] ==  (int)b.size())
			printf("%d ", i - 2 * (int)b.size() + 1);
	}
	return 0;
}
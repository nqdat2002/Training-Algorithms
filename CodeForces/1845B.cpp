#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;
pt A, B, C;
int dist(const pt &A, const pt &B) {
	return abs(A.x - B.x) + abs(A.y - B.y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		cin >> A.x >> A.y;
		cin >> B.x >> B.y;
		cin >> C.x >> C.y;
		cout << (dist(A, B) + dist(A, C) - dist(B, C)) / 2 + 1 << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int s1, s2, e1, e2; 
	cin >> s1 >> e1 >> s2 >> e2;
	cout << max (abs (s1 - e1), abs (s2 - e2));
}
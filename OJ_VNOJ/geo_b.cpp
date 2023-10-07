#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point{
	ll x, y;
};
// https://hayhochoi.vn/cach-viet-phuong-trinh-duong-phan-giac-cua-tam-giac-abc-trong-mat-phang-oxy-toan-10-chuyen-de.html
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	point A, B, C;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	point AB, AC;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;

	AC.x = C.x - A.x;
	AC.y = C.y - A.y;
	vector<ll> vAB;
	vAB.push_back(AB.x);
	vAB.push_back(AB.y);
	vAB.push_back(AB.x * (-A.x) + AB.y * (-A.y));

	vector<ll> vAC;
	vAC.push_back(AC.x);
	vAC.push_back(AC.y);
	vAC.push_back(AC.x * (-A.x) + AC.y * (-A.y));

	vector<ll> res1, res2;

	res1.push_back()
	return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// int n;
// int main(int argc, char const *argv[]) {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	int t; cin >> t;
// 	while (t--) {

// 		cout << endl;
// 	}
// 	return 0;
// }

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

long long sum_second_largest(const vector<int>& P) {
	int n = P.size();
	vector<int> next_greater(n, n);
	vector<int> prev_greater(n, -1);
	stack<int> s;

	// Tìm chỉ số của phần tử lớn hơn tiếp theo cho mỗi phần tử
	for (int i = 0; i < n; ++i) {
		while (!s.empty() && P[s.top()] < P[i]) {
			next_greater[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	// Làm trống stack để sử dụng lại
	while (!s.empty()) s.pop();

	// Tìm chỉ số của phần tử lớn hơn trước đó cho mỗi phần tử
	for (int i = n - 1; i >= 0; --i) {
		while (!s.empty() && P[s.top()] < P[i]) {
			prev_greater[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	long long total_sum = 0;

	// Tính tổng các giá trị lớn thứ hai cho mỗi đoạn
	for (int i = 0; i < n; ++i) {
		int left_bound = prev_greater[i] + 1;
		int right_bound = next_greater[i] - 1;
		int num_segments = (i - left_bound + 1) * (right_bound - i + 1);
		total_sum += static_cast<long long>(num_segments) * P[i];
	}

	return total_sum;
}

int main() {
	int n; cin >> n;
	vector<int> P(n);
	for (auto &x : P) cin >> x;
	cout << sum_second_largest(P) << endl; 
	return 0;
}

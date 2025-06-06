#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm đếm các bộ ba có tổng bằng 0 trong đoạn từ L đến R của mảng
int countTriplets(const vector<int>& arr, int L, int R) {
    vector<int> subArray(arr.begin() + L, arr.begin() + R + 1);
    sort(subArray.begin(), subArray.end());
    
    int count = 0;
    int n = subArray.size();
    
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && subArray[i] == subArray[i - 1]) continue; // Tránh trùng lặp
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = subArray[i] + subArray[left] + subArray[right];
            if (sum == 0) {
                count++;
                while (left < right && subArray[left] == subArray[left + 1]) left++; // Tránh trùng lặp
                while (left < right && subArray[right] == subArray[right - 1]) right--; // Tránh trùng lặp
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return count;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        cout << countTriplets(A, L, R) << endl;
    }
    
    return 0;
}

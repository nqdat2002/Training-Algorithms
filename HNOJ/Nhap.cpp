#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, L, R;
    cin >> n >> L >> R;

    vector<pair<int, int>> elements;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        elements.push_back(make_pair(a, i));
    }

    sort(elements.begin(), elements.end());

    vector<int> chosen_indices;
    int total = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (total + elements[i].first <= R) {
            total += elements[i].first;
            chosen_indices.push_back(elements[i].second);
        }
    }

    int num_chosen = chosen_indices.size();
    vector<int> result_indices;
    for (int mask = 0; mask < (1 << num_chosen); mask++) {
        int current_sum = 0;
        for (int i = 0; i < num_chosen; i++) {
            if (mask & (1 << i)) {
                current_sum += elements[chosen_indices[i] - 1].first;
            }
        }
        if (current_sum >= L && current_sum <= R) {
            result_indices.clear();
            for (int i = 0; i < num_chosen; i++) {
                if (mask & (1 << i)) {
                    result_indices.push_back(chosen_indices[i]);
                }
            }
            break;
        }
    }

    num_chosen = result_indices.size();
    cout << num_chosen << endl;
    for (int i = 0; i < num_chosen; i++) {
        cout << result_indices[i];
        if (i < num_chosen - 1) {
            cout << " ";
        }
    }

    return 0;
}

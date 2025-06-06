#include <iostream>
#include <vector>

void generate_combinations(int n, int k, int start, std::vector<int>& current_combination) {
    if (current_combination.size() == k) {
        for (int num : current_combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }
    
    for (int i = start; i <= n; ++i) {
        current_combination.push_back(i);
        generate_combinations(n, k, i, current_combination);
        current_combination.pop_back();
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> combination;
    generate_combinations(n, k, 1, combination);
    return 0;
}

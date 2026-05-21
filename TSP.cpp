#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> name = {"A", "B", "C", "D", "E"};
    int dist[5][5] = {
        {0,  9,  8, 14, 14}, // Đường từ A đến [A, B, C, D, E]
        {9,  0, 22, 10, 15}, // Đường từ B đến [A, B, C, D, E]
        {8, 22,  0,  8,  4}, // Đường từ C đến [A, B, C, D, E]
        {14, 10, 8,  0, 19}, // Đường từ D đến [A, B, C, D, E]
        {14, 15, 4, 19,  0}  // Đường từ E đến [A, B, C, D, E]
    };
    vector<int> vertices = {1, 2, 3, 4}; 
    
    int min_cost = INT_MAX;
    vector<int> best_path;

    do {
        int current_cost = dist[0][vertices[0]];
                for (int i = 0; i < 3; i++) {
            current_cost += dist[vertices[i]][vertices[i+1]];
        }
        
        current_cost += dist[vertices[3]][0];
        if (current_cost < min_cost) {
            min_cost = current_cost;
            best_path = vertices;
        }
    } while (next_permutation(vertices.begin(), vertices.end()));
    cout << "Tong so thu thach nho nhat: " << min_cost << endl;
    cout << "Duong di toi uu: A -> ";
    for (int v : best_path) {
        cout << name[v] << " -> ";
    }
    cout << "A" << endl;

    return 0;
}

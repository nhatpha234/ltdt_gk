#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Định nghĩa đồ thị bằng danh sách kề
unordered_map<char, vector<char>> graph = {
    {'S', {'A', 'B', 'C'}},
    {'A', {'D'}},
    {'B', {'E'}},
    {'C', {'F'}},
    {'D', {'G'}},
    {'E', {'G'}},
    {'F', {'G'}},
    {'G', {}}
};

// Hàm DFS sử dụng đệ quy
void DFS(char node, unordered_set<char> &visited) {
    // Đánh dấu đã thăm đỉnh này
    visited.insert(node);
    cout << node << " ";  // In ra đỉnh đang xét

    // Duyệt tất cả đỉnh kề
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            DFS(neighbor, visited);
        }
    }
}

int main() {
    unordered_set<char> visited;
    cout << "Duyệt DFS từ S: ";
    DFS('S', visited);
    return 0;
}
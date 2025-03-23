#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

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

// Hàm DFS sử dụng ngăn xếp (không đệ quy)
void DFS_Stack(char start) {
    unordered_set<char> visited;
    stack<char> s;
    s.push(start);

    while (!s.empty()) {
        char node = s.top();
        s.pop();

        // Nếu đỉnh chưa được thăm, xử lý nó
        if (visited.find(node) == visited.end()) {
            cout << node << " ";
            visited.insert(node);

            // Đẩy các đỉnh kề vào ngăn xếp (đảo ngược để giữ đúng thứ tự)
            vector<char> neighbors = graph[node];
            for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    s.push(*it);
                }
            }
        }
    }
}

int main() {
    cout << "Duyệt DFS từ S (dùng stack): ";
    DFS_Stack('S');
    return 0;
}
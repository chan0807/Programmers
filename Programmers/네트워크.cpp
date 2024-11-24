#include <string>
#include <vector>
#include <stack>

using namespace std;

namespace 네트워크 {
    void dfs(int node, const vector<vector<int>>& computers, vector<bool>& visited) {
        visited[node] = true;
        for (int j = 0; j < computers.size(); j++) {
            if (computers[node][j] == 1 && !visited[j]) {
                dfs(j, computers, visited);
            }
        }
    }

    void dfsStack(int node, vector<vector<int>>& computers, vector<bool>& visited) {
        stack<int> s;
        s.push(node);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            visited[current] = true;

            for (int i = 0; i < computers.size(); i++) {
                if (computers[current][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }

    int solution(int n, vector<vector<int>> computers) {
        int answer = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsStack(i, computers, visited);
                answer++;
            }
        }

        return answer;
    }
}
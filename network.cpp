#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer=0;
    stack<int> bfs;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++)
    {
        if(visited[i])
            continue;
        bfs.emplace(i);
        visited[i] = true;

        while(bfs.empty() == false)
        {
            int currentNode = bfs.top();
            bfs.pop();
            for(int node=0; node < n; node++)
            {
                if(visited[node] == false && computers[currentNode][node])
                {
                    bfs.emplace(node);
                    visited[node] = true;
                }
            }
        }
        answer++;
    }

    return answer;
}

// int main()
// {
//     int n = 3;
//     vector<vector<int>> computers = {{1, 1, 0}, {0, 1, 1}, {0, 1, 1}};
//     solution(n, computers);
//     return 0;
// }
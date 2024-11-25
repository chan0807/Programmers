#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MOD 1000000007

namespace 등굣길 {
    int solution(int m, int n, vector<vector<int>> puddles) {
        int answer = 0;

        pair<int, int> startPos = { 1,1 };
        vector<vector<bool>> grid(n, vector<bool>(m, true));

        for (const auto& puddle : puddles) {
            int x = puddle[0] - 1;
            int y = puddle[1] - 1;
            grid[y][x] = false;
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        vector<vector<int>> ways(n, vector<int>(m, 0));

        q.push({ 0, 0 });
        dist[0][0] = 0;
        ways[0][0] = 1;

        vector<pair<int, int>> directions = {
            {1, 0},
            {0, 1}
        };

        while (!q.empty()) {
            pair<int, int> qFront = q.front();
            int x = qFront.first;
            int y = qFront.second;
            q.pop();

            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newY][newX]) {
                    if (dist[newY][newX] == -1) {
                        dist[newY][newX] = dist[y][x] + 1;
                        ways[newY][newX] = ways[y][x];
                        q.push({ newX, newY });
                    }
                    else if (dist[newY][newX] == dist[y][x] + 1) {
                        ways[newY][newX] = (ways[newY][newX] + ways[y][x]) % MOD;
                    }
                }
            }
        }
        answer = ways[n - 1][m - 1] % MOD;
        return answer;
    }
}
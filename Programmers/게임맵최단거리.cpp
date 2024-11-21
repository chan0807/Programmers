#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

namespace 게임맵최단거리 {
    int bfs(vector<vector<int>>& maps) {
        int h = maps.size();
        int w = maps[0].size();

        vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        queue<pair<pair<int, int>, int>> q; // {{x, y}, 이동 횟수}
        q.push({ {0, 0}, 1 });
        visited[0][0] = true;

        while (!q.empty()) {
            pair<pair<int, int>, int> current = q.front();
            pair<int, int> curPos = current.first;
            int nMoveCount = current.second;
            q.pop();

            int x = curPos.first;
            int y = curPos.second;

            if (x == h - 1 && y == w - 1) {
                return nMoveCount;
            }

            for (const auto& dir : directions) {
                int nextX = x + dir.first;
                int nextY = y + dir.second;

                if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w
                    && maps[nextX][nextY] == 1 && !visited[nextX][nextY]) 
                {
                    visited[nextX][nextY] = true;
                    q.push({ {nextX, nextY}, nMoveCount + 1 });
                }
            }
        }

        return -1;
    }

    int solution(vector<vector<int>> maps)
    {
        int answer = bfs(maps);

        return answer;
    }
}
#include<vector>
#include <queue>

using namespace std;
namespace gameMap {
	enum {
		PAST = -1,		
		BLOCKED,
		OPEN,
	};

	/* dfs / bfs 안쓰고 하고싶었으나 실패..최단거리 아님 */
	int solution2(vector<vector<int>> maps) {
		const int m = maps.size() - 1;
		const int n = maps[0].size() - 1;

		while (1) {						
			for (int i = 0; i <= m; i++)			
				for (int j = 0; j <= n; j++)
					if (maps[i][j] == PAST) maps[i][j] = OPEN;
			
			int h = 0, w = 0, step = 1;
			while (1) {
				if (h == m && w == n) return step;

				maps[h][w] = PAST;

				step++;

				if (h < m && maps[h + 1][w] == OPEN) h++;

				else if (w < n && maps[h][w + 1] == OPEN) w++;

				else if (w > 0 && maps[h][w - 1] == OPEN) w--;

				else if (h > 0 && maps[h - 1][w] == OPEN) h--;

				else {
					if (h == 0 && w == 0) return -1;

					maps[h][w] = BLOCKED;				
					break;
				}					
			}
		}
	}

	int solution(vector<vector<int>> maps) {
		int m = maps.size();
		int n = maps[0].size();
		vector<vector<int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		maps[0][0] = PAST;

		int steps = 1;

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto [h, w] = q.front();
				q.pop();

				if (h == m - 1 && w == n - 1) return steps;

				for (const auto& dir : directions) {
					int nh = h + dir[0];
					int nw = w + dir[1];

					if (nh >= 0 && nh < m && nw >= 0 && nw < n && maps[nh][nw] == OPEN) {
						maps[nh][nw] = PAST;
						q.push({ nh, nw });
					}
				}
			}
			steps++;
		}

		return -1;
	}
}
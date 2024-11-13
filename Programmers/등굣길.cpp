#include <string>
#include <vector>
#define HOLE -1
#define MOD 1000000007

using namespace std;
namespace school {

	int solution(int m, int n, vector<vector<int>> puddles) {
		
		vector<vector<int>> map = vector<vector<int>>(n, vector<int>(m, 0));
		
		for (int i = 0; i < puddles.size(); i++) {
			map[puddles[i][1] - 1][puddles[i][0] - 1] = HOLE;
		}

		map[0][0] = 1;

		for (int i = 0; i < n; i++) {
			if (map[i][0] == HOLE) {
				break;
			}
			map[i][0] = 1;
		}

		for (int i = 0; i < m; i++) {
			if (map[0][i] == HOLE) {
				break;
			}
			map[0][i] = 1;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {

				int& current = map[i][j];
				if (current == HOLE) {
					continue;
				}

				const int up = map[i - 1][j];
				if (up != HOLE) {				
					current = (current + up) % MOD;
				}

				const int left = map[i][j - 1];
				if (left != HOLE) {					
					current = (current + left) % MOD;
				}
			}
		}

		return map[n - 1][m - 1];
	}
}
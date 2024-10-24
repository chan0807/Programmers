#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace 피로도 {
	int solution(int k, vector<vector<int>> dungeons) {
		int maxCnt = 0;
		sort(dungeons.begin(), dungeons.end());
		do {
			int health = k, cnt = 0;
			for (auto& dungeon : dungeons) {
				if (health >= dungeon[0]) {
					health -= dungeon[1];
					cnt++;
				}
			}
			maxCnt = max(maxCnt, cnt);
		} while (next_permutation(dungeons.begin(), dungeons.end()));

		return maxCnt;
	}
}
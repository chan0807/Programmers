#include <string>
#include <vector>

using namespace std;
namespace Á¤¼ö_»ï°¢Çü {
	int solution(vector<vector<int>> triangle) {
		int answer = 0;

		int total_cnt = triangle.size() - 1;
		for (int i = 0; i < total_cnt; i++) {

			vector<int>& prev = triangle[i];
			vector<int>& current = triangle[i + 1];

			for (int j = 0; j < current.size(); j++) {
				if (j == 0) {
					current[j] += prev[j];
				}
				else if (j == current.size() - 1) {
					current[j] += prev[j - 1];
				}
				else {
					current[j] += max(prev[j - 1], prev[j]);
				}
			}
		}
		answer = *max_element(triangle.back().begin(), triangle.back().end());
		return answer;
	}
}
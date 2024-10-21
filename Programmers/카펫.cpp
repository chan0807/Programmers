#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace Ä«Æê {

	using namespace std;
	vector<int> solution(int brown, int yellow) {
		vector<int> answer;

		for (int i = 1; i <= yellow; i++) {
			if (yellow % i == 0) {
				int h = i;
				int w = yellow / i;

				if (h + w == (brown - 4) / 2) {
					answer.push_back(w + 2);
					answer.push_back(h + 2);
					break;
				}
			}
		}

		sort(answer.begin(), answer.begin() + 2, greater<int>());

		return answer;
	}
}
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	for (int i = 0; i < 100; i++) {

		int cnt = 0;
		if (progresses.front() >= 100) {
			for (int k = 0; k < progresses.size(); k++) {
				if (progresses[k] >= 100) {
					cnt++;
				}
				else {
					break;
				}
			}
			answer.push_back(cnt);
		}

		for (int j = 0; j < cnt; j++)
		{
			progresses.erase(progresses.begin());
			speeds.erase(speeds.begin());
			if (progresses.size() == 0)
				return answer;
		}

		for (int j = 0; j < speeds.size(); j++) {
			progresses[j] += speeds[j];
		}
	}

	return answer;
}
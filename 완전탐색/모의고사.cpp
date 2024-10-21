#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define SUPOJANUM 3



vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<vector<int>> Supoja = { {1, 2, 3, 4, 5},{2, 1, 2, 3, 2, 4, 2, 5},{3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };
	vector<int> AnswerCount = { 0,0,0 };

	for (int i = 0; i < SUPOJANUM; i++)
	{
		int num = Supoja[i].size();
		for (int j = 0; j < answers.size(); j++)
		{
			if (Supoja[i][j % num] == answers[j]) {
				AnswerCount[i]++;
			}
		}
	}

	int maxCount = *max_element(AnswerCount.begin(), AnswerCount.end());

	for (int i = 0; i < SUPOJANUM; i++) {
		if (AnswerCount[i] == maxCount) {
			answer.push_back(i + 1);
		}
	}
	return answer;
}
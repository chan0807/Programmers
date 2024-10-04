#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++)
	{
		int time = prices.size() - i - 1;
		int p = prices[i];
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (p > prices[j])
			{
				time = j - i;
				break;
			}
		}
		answer.push_back(time);
	}


	return answer;
}
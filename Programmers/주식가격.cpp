#include <string>
#include <vector>
#include <stack>

using namespace std;

namespace 주식가격 {
	vector<int> solution(vector<int> prices) { //stack 활용
		int nSize = prices.size();
		vector<int> answer(nSize, 0);
		stack<int> stIndex;

		for (int i = 0; i < nSize; ++i)
		{
			while (!stIndex.empty() && prices[i] < prices[stIndex.top()])
			{
				int nFrontIndex = stIndex.top();
				stIndex.pop();

				answer[nFrontIndex] = i - nFrontIndex;
			}

			stIndex.push(i);
		}

		while (!stIndex.empty())
		{
			int nLeftFrontIndex = stIndex.top();
			stIndex.pop();

			answer[nLeftFrontIndex] = nSize - nLeftFrontIndex - 1;
		}

		return answer;
	}
}
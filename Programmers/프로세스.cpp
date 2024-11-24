#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

namespace 프로세스 {
	int solution1(vector<int> priorities, int location) //queue 활용
	{
		queue<int> printer;								//queue에 index 삽입.
		vector<int> sorted;								//정렬된 결과 저장용
		for (int i = 0; i < priorities.size(); i++)
		{
			printer.push(i);
		}

		while (!printer.empty()) //printer 다 삭제될때까지 실행
		{
			int now_index = printer.front(); //큐 printer의 첫번째 요소 index 저장
			printer.pop();					 //큐 printer에 첫번째로 삽입된 요소 삭제
			if (priorities[now_index] != *max_element(priorities.begin(), priorities.end())) //전체 벡터에서 최대값 추출해서 비교
			{
				//아닌경우 push
				printer.push(now_index);	 //큐 printer에 다시 삽입 (맨 마지막)
			}

			else
			{
				//맞는경우
				sorted.push_back(now_index); //실행순서 저장
				priorities[now_index] = 0;   //priorities 값을 0으로 (최대값 아니게)
			}
		}

		for (int i = 0; i < sorted.size(); i++)
		{
			if (sorted[i] == location) return i + 1;
		}
	}

	int solution2(vector<int> priorities, int location) //unordered_set 활용
	{
		int answer = 0;

		unordered_set<int> numSet(priorities.begin(), priorities.end());

		vector<int> sortedSet(numSet.begin(), numSet.end());
		sort(sortedSet.begin(), sortedSet.end(), greater<int>());

		for (auto Max : sortedSet)
		{
			int lastMaxIndex = -1;

			for (int i = 0; i < priorities.size(); i++)
			{
				if (Max == priorities[i])
				{
					answer++;
					lastMaxIndex = i;  // Max 인덱스 저장
				}

				if (Max == priorities[i] && i == location)
				{
					return answer;
				}
			}

			vector<int> newPriorities;

			for (int i = lastMaxIndex + 1; i < priorities.size(); i++)
			{
				newPriorities.push_back(priorities[i]);
			}

			location += newPriorities.size();

			if (location >= priorities.size())
			{
				location %= priorities.size();
			}

			for (int i = 0; i <= lastMaxIndex; i++)
			{
				if (priorities[i] == Max)
				{
					newPriorities.push_back(0);
				}
				else
				{
					newPriorities.push_back(priorities[i]);
				}
			}

			priorities = newPriorities;
		}

		return answer;
	}
}
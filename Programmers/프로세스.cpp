#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

namespace ���μ��� {
	int solution1(vector<int> priorities, int location) //queue Ȱ��
	{
		queue<int> printer;								//queue�� index ����.
		vector<int> sorted;								//���ĵ� ��� �����
		for (int i = 0; i < priorities.size(); i++)
		{
			printer.push(i);
		}

		while (!printer.empty()) //printer �� �����ɶ����� ����
		{
			int now_index = printer.front(); //ť printer�� ù��° ��� index ����
			printer.pop();					 //ť printer�� ù��°�� ���Ե� ��� ����
			if (priorities[now_index] != *max_element(priorities.begin(), priorities.end())) //��ü ���Ϳ��� �ִ밪 �����ؼ� ��
			{
				//�ƴѰ�� push
				printer.push(now_index);	 //ť printer�� �ٽ� ���� (�� ������)
			}

			else
			{
				//�´°��
				sorted.push_back(now_index); //������� ����
				priorities[now_index] = 0;   //priorities ���� 0���� (�ִ밪 �ƴϰ�)
			}
		}

		for (int i = 0; i < sorted.size(); i++)
		{
			if (sorted[i] == location) return i + 1;
		}
	}

	int solution2(vector<int> priorities, int location) //unordered_set Ȱ��
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
					lastMaxIndex = i;  // Max �ε��� ����
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
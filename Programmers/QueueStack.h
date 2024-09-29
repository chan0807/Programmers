#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

// 3. ���μ��� - 1: vector�� ���� ����....
int QueueThree1(vector<int> priorities, int location)
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

// 3. ���μ��� - 2: queue Ȱ��
int QueueThree2(vector<int> priorities, int location)
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

// 2. �ùٸ� ��ȣ
bool QueueTwo(string s)
{
	bool answer = true;

	std::unordered_map<char, int> strMap;

	strMap['('] = 0;
	strMap[')'] = 0;

	for (char c : s)
	{
		if (c == '(')
		{
			strMap['(']++;
		}

		else if (c == ')')
		{
			strMap[')']++;
		}

		if (strMap[')'] > strMap['('])
		{
			answer = false;
			break;
		}
	}

	if (strMap['('] != strMap[')'])
	{
		answer = false;
	}

	return answer;
}

// 1. ��ɰ��� -1: vector Ȱ��
vector<int> QueueOne1(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	while (!progresses.empty())
	{
		int nCount = progresses.size();

		for (size_t i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];
		}

		while (!progresses.empty() && progresses[0] >= 100)
		{
			progresses.erase(progresses.begin());
			speeds.erase(speeds.begin());
		}

		if (progresses.size() != nCount)
		{
			answer.push_back(nCount - progresses.size());
		}
	}

	return answer;
}

// 1. ��ɰ��� -2: queue Ȱ��
vector<int> QueueOne2(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	//Queue Ȱ��
	queue<int> progressQueue;
	queue<int> speedQueue;

	// progresses�� speeds�� ���� ť�� ����
	for (int i = 0; i < progresses.size(); i++)
	{
		progressQueue.push(progresses[i]);
		speedQueue.push(speeds[i]);
	}

	while (!progressQueue.empty())
	{
		// ��� �۾��� ���� �Ϸ�ġ ���� ��Ȳ�� ������Ʈ
		int nCount = 0;

		// �� �۾��� �ӵ���ŭ ����
		int queueSize = progressQueue.size();
		for (int i = 0; i < queueSize; i++)
		{
			int currentProgress = progressQueue.front();
			progressQueue.pop();
			int currentSpeed = speedQueue.front();
			speedQueue.pop();

			currentProgress += currentSpeed; // �ӵ���ŭ ����

			// �ٽ� ť�� ���� (100% �Ϸ���� ���� �۾��鸸)
			if (currentProgress < 100)
			{
				progressQueue.push(currentProgress);
				speedQueue.push(currentSpeed);
			}
		}

		// �Ϸ�� �۾����� üũ
		while (!progressQueue.empty() && progressQueue.front() >= 100)
		{
			progressQueue.pop();
			speedQueue.pop();
			nCount++; // �Ϸ�� �۾� ���� ����
		}

		if (nCount > 0)
		{
			answer.push_back(nCount); // �Ϸ�� �۾� ���� ����
		}
	}

	return answer;
}
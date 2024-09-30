#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

// 3. 프로세스 - 1: vector로 정면 돌파....
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

// 3. 프로세스 - 2: queue 활용
int QueueThree2(vector<int> priorities, int location)
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

// 2. 올바른 괄호
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

// 1. 기능개발 -1: vector 활용
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

// 1. 기능개발 -2: queue 활용
vector<int> QueueOne2(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	//Queue 활용
	queue<int> progressQueue;
	queue<int> speedQueue;

	// progresses와 speeds를 각각 큐에 삽입
	for (int i = 0; i < progresses.size(); i++)
	{
		progressQueue.push(progresses[i]);
		speedQueue.push(speeds[i]);
	}

	while (!progressQueue.empty())
	{
		// 모든 작업에 대해 하루치 진행 상황을 업데이트
		int nCount = 0;

		// 각 작업을 속도만큼 진행
		int queueSize = progressQueue.size();
		for (int i = 0; i < queueSize; i++)
		{
			int currentProgress = progressQueue.front();
			progressQueue.pop();
			int currentSpeed = speedQueue.front();
			speedQueue.pop();

			currentProgress += currentSpeed; // 속도만큼 진행

			// 다시 큐에 삽입 (100% 완료되지 않은 작업들만)
			if (currentProgress < 100)
			{
				progressQueue.push(currentProgress);
				speedQueue.push(currentSpeed);
			}
		}

		// 완료된 작업들을 체크
		while (!progressQueue.empty() && progressQueue.front() >= 100)
		{
			progressQueue.pop();
			speedQueue.pop();
			nCount++; // 완료된 작업 개수 증가
		}

		if (nCount > 0)
		{
			answer.push_back(nCount); // 완료된 작업 수를 저장
		}
	}

	return answer;
}
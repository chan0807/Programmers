#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

/*------------------------------------------- Queue/Stack -------------------------------------------*/

// 1. ��ɰ���
vector<int> QueueOne(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	// ���� Ǯ��
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

/*------------------------------------------- Hash -------------------------------------------*/

// 1. �������� ���� ����
string HashOne(vector<string> participant, vector<string> completion) {
	string answer = "";

	// �ؽ�Ȱ��
	unordered_map<string, int> countMap;

	for (const string& name : completion)
	{
		countMap[name]++;
	}

	for (const string& name : participant)
	{
		if (countMap[name] > 0)
		{
			countMap[name]--;
		}
		else
		{
			answer = name;
			break;
		}
	}

	return answer;
}

// 2. ��ȭ��ȣ ���
bool HashTwo(vector<string> phone_book) {
    bool answer = true;

    // �ؽ� Ȱ��
    unordered_map<string, int> prefixMap;

    for (const string& number : phone_book)
    {
        prefixMap[number] = 1;
    }

    // �� ��ȣ�� ���λ� ���� Ȯ��
    for (const string& number : phone_book)
    {
        for (int i = 1; i <= number.length(); ++i)
        {
            string prefix = number.substr(0, i);
            if (prefixMap.find(prefix) != prefixMap.end() && prefix != number)
            {
                answer = false;
            }
        }
    }

    return answer;
}
/*--------------------------------------------------------------------------------------------*/

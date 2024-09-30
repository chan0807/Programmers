#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

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
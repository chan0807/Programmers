#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 1. 완주하지 못한 선수
string HashOne(vector<string> participant, vector<string> completion) {
	string answer = "";

	// 해시활용
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

// 2. 전화번호 목록
bool HashTwo(vector<string> phone_book) {
    bool answer = true;

    // 해시 활용
    unordered_map<string, int> prefixMap;

    for (const string& number : phone_book)
    {
        prefixMap[number] = 1;
    }

    // 각 번호의 접두사 여부 확인
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
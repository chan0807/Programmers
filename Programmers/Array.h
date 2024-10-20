#pragma once

#include <string>
#include <vector>
#include <queue>

using namespace std;

bool compare(string a, string b)
{
	return a + b > b + a;
}

string ArrayTwo(vector<int> numbers) {
	string answer = "";

	vector<string> strNumbers;
	for (int num : numbers) 
	{
		strNumbers.push_back(to_string(num));
	}

	sort(strNumbers.begin(), strNumbers.end(), compare);

	for (const string& num : strNumbers) 
	{
		answer += num;
	}

	if (answer[0] == '0') 
	{
		return "0";
	}

	return answer;
}

vector<int> ArrayOne(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (const auto& command : commands)
    {
        vector<int> result = {};

        const int nStartIndex = command[0]-1;
        const int nEndIndex = command[1]-1;
        const int nResultIndex = command[2]-1;

        for (int i = nStartIndex; i <= nEndIndex; i++)
        {
            result.push_back(array[i]);
        }

        sort(result.begin(), result.end());

        answer.push_back(result[nResultIndex]);
    }

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace ����ū�� {
	bool compare(string a, string b)
	{
		return a + b > b + a;
	}

	string solution(vector<int> numbers) {
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

}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

namespace ¿Ã¹Ù¸¥°ýÈ£ {
	bool solution(string s)
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
}
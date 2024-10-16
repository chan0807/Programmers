#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), [](int a, int b) {
		string s1 = to_string(a);
		string s2 = to_string(b);
		return s1 + s2 > s2 + s1;
		});

	for (int number : numbers) {
		answer += to_string(number);
	}

	if (answer[0] == '0') return "0";

	return answer;
}
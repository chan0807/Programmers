#include <string>
#include <vector>

using namespace std;
namespace targetNumber {
	void operation(vector<int>& sumList, const int num) {
		vector<int> tempList;
		for (auto sum : sumList) {
			tempList.push_back(sum + (-1 * num));
			tempList.push_back(sum + num);
		}
		sumList = tempList;
	}

	int solution(vector<int> numbers, int target) {
		vector<int> sumList;
		for (const auto& number : numbers) {
			if (sumList.empty()) {
				sumList.push_back(number);
				sumList.push_back(-1 * number);
			}
			else operation(sumList, number);
		}
		return count(sumList.begin(), sumList.end(), target);
	}
}
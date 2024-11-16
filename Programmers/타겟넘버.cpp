#include <string>
#include <vector>

using namespace std;

namespace Å¸°Ù³Ñ¹ö {

    void getSum(const vector<int>& numbers, int nCurrentK, vector<int>& aSum, int index) {
        if (index == numbers.size()) {
            aSum.push_back(nCurrentK);
            return;
        }

        getSum(numbers, nCurrentK + numbers[index], aSum, index + 1);
        getSum(numbers, nCurrentK - numbers[index], aSum, index + 1);
    }

    int solution(vector<int> numbers, int target) {
        int answer = 0;

        vector<int> aSum;
        getSum(numbers, 0, aSum, 0);

        for (const auto& sum : aSum) {
            if (sum == target)
                answer++;
        }

        return answer;
    }
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace K¹øÂ°¼ö {
    vector<int> solution(vector<int> array, vector<vector<int>> commands) {
        vector<int> answer;

        for (const auto& command : commands)
        {
            vector<int> result = {};

            const int nStartIndex = command[0] - 1;
            const int nEndIndex = command[1] - 1;
            const int nResultIndex = command[2] - 1;

            for (int i = nStartIndex; i <= nEndIndex; i++)
            {
                result.push_back(array[i]);
            }

            sort(result.begin(), result.end());

            answer.push_back(result[nResultIndex]);
        }

        return answer;
    }
}
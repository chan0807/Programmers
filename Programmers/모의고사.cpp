#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace 모의고사 {
    vector<int> solution(vector<int> answers) {
        vector<int> answer;
        vector<pair<int, int>> result = { {0,1},{0,2},{0,3} }; // answerCount,Index

        vector<int> aOne = { 1,2,3,4,5 };
        vector<int> aTwo = { 2,1,2,3,2,4,2,5 };
        vector<int> aThree = { 3,3,1,1,2,2,4,4,5,5 };

        queue<int> qOne;
        queue<int> qTwo;
        queue<int> qThree;

        for (const auto& One : aOne)
        {
            qOne.push(One);
        }

        for (const auto& Two : aTwo)
        {
            qTwo.push(Two);
        }

        for (const auto& Three : aThree)
        {
            qThree.push(Three);
        }

        for (const auto& ans : answers)
        {
            int nOneAnswer = qOne.front();
            int nTwoAnswer = qTwo.front();
            int nThreeAnswer = qThree.front();

            qOne.pop();
            qTwo.pop();
            qThree.pop();

            if (nOneAnswer == ans)
            {
                result[0].first++;
            }

            if (nTwoAnswer == ans)
            {
                result[1].first++;
            }

            if (nThreeAnswer == ans)
            {
                result[2].first++;
            }

            qOne.push(nOneAnswer);
            qTwo.push(nTwoAnswer);
            qThree.push(nThreeAnswer);
        }

        sort(result.begin(), result.end(), [](pair<int, int> a, pair<int, int> b)
            {
                if (a.first != b.first)
                {
                    return a.first > b.first;  // first ↘
                }
                else
                {
                    return a.second < b.second; // second ↗
                }
            });

        int nMax = result[0].first;

        for (const auto& re : result)
        {
            if (re.first != 0 && nMax <= re.first)
            {
                answer.push_back(re.second);
            }
        }

        return answer;
    }
}
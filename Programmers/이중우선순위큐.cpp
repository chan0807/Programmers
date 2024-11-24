#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

namespace 이중우선순위큐 {
    vector<int> solution1(vector<string> operations) { //using priority_queue
        vector<int> answer = { 0,0 };

        string sDeleteMin = "D -1";
        string sDeleteMax = "D 1";

        priority_queue<int> maxHeap;

        for (const auto& operation : operations)
        {
            if (operation == sDeleteMin && !maxHeap.empty())
            {
                priority_queue<int, vector<int>, greater<int>> minHeap;

                while (!maxHeap.empty())
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }

                if (!minHeap.empty())
                {
                    minHeap.pop(); //Delete Min Value
                }

                while (!minHeap.empty())
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }

            else if (operation == sDeleteMax && !maxHeap.empty())
            {
                maxHeap.pop(); //Delete Max Value
            }

            else if (operation.substr(0, 2) == "I ")
            {
                string sNum = operation.substr(2);
                int nNum = stoi(sNum);

                maxHeap.push(nNum);
            }
        }

        vector<int> results;

        while (!maxHeap.empty())
        {
            results.push_back(maxHeap.top());
            maxHeap.pop();
        }

        if (!results.empty() && results.size() > 1)
        {
            for (int i = 0; i < results.size(); i++)
            {
                if (i == 0)
                {
                    answer[0] = results[i];
                }

                else if (i == results.size() - 1)
                {
                    answer[1] = results[i];
                }
            }

            return answer;
        }

        else if (!results.empty() && results.size() == 1)
        {
            answer[0] = results[0], answer[1] = results[0];

            return answer;
        }

        return answer;
    }

    vector<int> solution2(vector<string> arguments) { //using multiset
        vector<int> answer;
        multiset<int> que; // -> 1,2,3,4,5 
        string sub;

        for (auto s : arguments)
        {
            sub = s.substr(0, 2);

            if (sub == "I ")
            {
                int num = stoi(s.substr(2));
                que.insert(num);
            }

            else if (s.substr(2, 1) == "1" && !que.empty())
            {
                auto it = --que.end();
                que.erase(it); //Delete Max Value
            }

            else if (!que.empty())
            {
                auto it = que.begin();
                que.erase(it); //Delete Min Value
            }
        }

        if (que.empty())
        {
            answer.push_back(0);
            answer.push_back(0);
        }

        else
        {
            int maxVal = *que.rbegin(); // rbegin() -> Last Index (Max Value)
            int minVal = *que.begin();  // begin() -> Fisrt Index (Min Value)
            answer.push_back(maxVal);
            answer.push_back(minVal);
        }

        return answer;
    }
}
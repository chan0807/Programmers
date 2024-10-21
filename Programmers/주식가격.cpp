#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace 주식가격 {
    //deque 이용 방식
    vector<int> solution(vector<int> prices) {
        vector<int> answer;
        deque<int> dq;

        for (int i : prices)
            dq.push_back(i);

        while (!dq.empty())
        {
            int cur = dq.front();
            dq.pop_front();

            int cnt = 0;
            for (int i : dq)
            {
                cnt++;
                if (cur > i) break;
            }

            answer.push_back(cnt);
        }

        return answer;
    }

    /*
        vector만 이용해서 푸는 경우
        루프를 최대한 간소화해서 속도 측면에서 우월함
    */
    vector<int> solution2(vector<int> prices) {
        vector<int> answer(prices.size());

        for (size_t i = 0; i < prices.size(); ++i) {
            int cnt = 0;
            for (size_t j = i + 1; j < prices.size(); ++j) {
                cnt++;
                if (prices[i] > prices[j]) break;
            }
            answer[i] = cnt;
        }

        return answer;
    }
}
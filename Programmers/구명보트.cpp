#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

namespace 구명보트 {
    int solution(vector<int> people, int limit) {
        int answer = 0;

        sort(people.begin(), people.end(), greater<int>());
        deque<int> dQueue(people.begin(), people.end());
     
        while (!dQueue.empty()) {
            if (dQueue.size() > 1 && dQueue.front() + dQueue.back() > limit) {
                dQueue.pop_front();
                answer++;
            }
            else if (dQueue.size() > 1 && dQueue.front() + dQueue.back() <= limit) {
                dQueue.pop_front();
                dQueue.pop_back();
                answer++;
            }
            else {
                dQueue.pop_back();
                answer++;
            }
        }

        return answer;
    }
}
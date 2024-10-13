#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, cnt = 0;
    int pre_location = -1, cur_location = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    while (cnt < jobs.size()) {       
        for (const auto& job : jobs) {
            if (pre_location < job[0] && job[0] <= cur_location) {
                heap.push({ job[1], job[0] });
            }
        }

        if (!heap.empty()) {
            auto work = heap.top(); heap.pop();
            pre_location = cur_location;
            cur_location += work.first;
            answer += (cur_location - work.second);
            cnt++;
        }
        else {
            cur_location++;
        }
    }

    return answer / jobs.size();
}

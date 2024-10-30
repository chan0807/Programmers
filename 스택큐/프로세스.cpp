#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    for (const auto& v : priorities)
    {
        pq.push(v);
    }

    int index = 0;
    while (1)
    {
        index %= priorities.size();
        if (priorities[index] == pq.top())
        {
            pq.pop();
            answer++;
            if (location == index) return answer;
        }
        index++;
    }
    return answer;
}

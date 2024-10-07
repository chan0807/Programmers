#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    for (auto& s : scoville)
    {
        pq.push(s);
    }
    if (K <= pq.top()) return answer;
    while (pq.size() > 1)
    {
        answer++;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int sco = a + b * 2;
        pq.push(sco);
        if (K <= pq.top()) return answer;
    }

    return -1;
}
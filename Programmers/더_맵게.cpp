#include <string>
#include <vector>
#include <queue>

using namespace std;
using MinimumHeap = priority_queue<int, vector<int>, greater<>>;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    MinimumHeap min_heap(scoville.begin(), scoville.end());

    while (min_heap.size() > 1) {
        int min = min_heap.top();
        min_heap.pop();

        if (min >= K) break;

        int min_second = min_heap.top();
        min_heap.pop();

        int new_min = min + (min_second * 2);
        min_heap.push(new_min);

        answer++;
    }

    if (min_heap.top() < K) return -1;

    return answer;
}
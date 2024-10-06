#pragma once

#include <string>
#include <vector>
#include <queue>

using namespace std;

int HeapOne(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> qSortedScoville;

    for (const auto& s : scoville)
    {
        qSortedScoville.push(s);
    }

    while (qSortedScoville.top() < K)
    {
        if (qSortedScoville.size() < 2) 
        {
            return -1;
        }

        int nFisrt = qSortedScoville.top();
        qSortedScoville.pop();

        int nSecond = qSortedScoville.top();
        qSortedScoville.pop();

        int nResult = nFisrt + nSecond * 2;

        qSortedScoville.push(nResult);

        answer++;
    }

    return answer;
}
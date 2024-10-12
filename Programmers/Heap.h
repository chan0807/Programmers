#pragma once

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

//using multiset
vector<int> HeapThree2(vector<string> arguments) { 
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

//using priority_queue
vector<int> HeapThree1(vector<string> operations) {
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

    if (!results.empty() && results.size()>1)
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

int HeapTwo(vector<vector<int>> jobs) {
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    //jobs[시작시간, 작업시간] -> 시작시간이 짧은 순으로 정렬
    sort(jobs.begin(), jobs.end());

    int nSumTime = 0;   //전체 소요시간
    int nTime = 0;      //현재 시간
    int nIndex = 0;     //다음 작업의 인덱스

    while (nIndex < jobs.size() || !minHeap.empty())
    {
        //현재 시간에 시작할 수 있는 작업을 우선순위 큐에 추가
        while (nIndex < jobs.size() && jobs[nIndex][0] <= nTime) 
        {
            int nTakingTime = jobs[nIndex][1]; //작업 소요시간
            minHeap.push({ nTakingTime, jobs[nIndex][0] }); //minHeap[작업시간, 시작시간] -> 작업시간이 짧은 순으로 정렬
            nIndex++;
        }

        if(!minHeap.empty())
        {
            //가장 짧은 소요 시간을 가진 job
            auto currentJob = minHeap.top();
            minHeap.pop();

            nTime += currentJob.first;              //현재시간 += 작업시간
            nSumTime += nTime - currentJob.second;  //전체 소요시간 += 현재시간 - 시작시간
        }
        else 
        {
            nTime++;
        }
    }

    answer = nSumTime / jobs.size();

    return answer;
}

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
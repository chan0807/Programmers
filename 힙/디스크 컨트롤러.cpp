#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b) { return a[1] > b[1]; }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur_time = 0;
    int index = 0;
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    while (index < jobs.size() || !pq.empty())
    {
        if (index < jobs.size() && jobs[index][0] <= cur_time)
        {
            pq.push(jobs[index++]);
            continue;
        }

        if (!pq.empty())
        {

            answer += cur_time - pq.top()[0] + pq.top()[1];
            cur_time += pq.top()[1];
            pq.pop();
        }
        else {
            cur_time = jobs[index][0];
        }

    }
    return answer / index;
}


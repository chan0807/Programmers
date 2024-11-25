#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace ��ũ��Ʈ�ѷ� {
    int solution(vector<vector<int>> jobs)
    {
        int answer = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        //jobs[���۽ð�, �۾��ð�] -> ���۽ð��� ª�� ������ ����
        sort(jobs.begin(), jobs.end());

        int nSumTime = 0;   //��ü �ҿ�ð�
        int nTime = 0;      //���� �ð�
        int nIndex = 0;     //���� �۾��� �ε���

        while (nIndex < jobs.size() || !minHeap.empty())
        {
            //���� �ð��� ������ �� �ִ� �۾��� �켱���� ť�� �߰�
            while (nIndex < jobs.size() && jobs[nIndex][0] <= nTime)
            {
                int nTakingTime = jobs[nIndex][1]; //�۾� �ҿ�ð�
                minHeap.push({ nTakingTime, jobs[nIndex][0] }); //minHeap[�۾��ð�, ���۽ð�] -> �۾��ð��� ª�� ������ ����
                nIndex++;
            }

            if (!minHeap.empty())
            {
                //���� ª�� �ҿ� �ð��� ���� job
                auto currentJob = minHeap.top();
                minHeap.pop();

                nTime += currentJob.first;              //����ð� += �۾��ð�
                nSumTime += nTime - currentJob.second;  //��ü �ҿ�ð� += ����ð� - ���۽ð�
            }
            else
            {
                nTime++;
            }
        }

        answer = nSumTime / jobs.size();

        return answer;
    }
}
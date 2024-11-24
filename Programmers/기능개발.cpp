#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace 기능개발 {
	vector<int> solution1(vector<int> progresses, vector<int> speeds) 
	{
		vector<int> answer;

		while (!progresses.empty()) {

			int nCount = progresses.size();

			for (size_t i = 0; i < progresses.size(); i++) {
				progresses[i] += speeds[i];
			}

			while (!progresses.empty() && progresses[0] >= 100) {
				progresses.erase(progresses.begin());
				speeds.erase(speeds.begin());
			}

			if (progresses.size() != nCount)
			{
				answer.push_back(nCount - progresses.size());
			}
		}

		return answer;
	}

	vector<int> solution2(vector<int> progresses, vector<int> speeds) 
	{
		vector<int> answer;

		//Queue 활용
		queue<int> progressQueue;
		queue<int> speedQueue;

		// progresses와 speeds를 각각 큐에 삽입
		for (int i = 0; i < progresses.size(); i++)
		{
			progressQueue.push(progresses[i]);
			speedQueue.push(speeds[i]);
		}

		while (!progressQueue.empty())
		{
			// 모든 작업에 대해 하루치 진행 상황을 업데이트
			int nCount = 0;

			// 각 작업을 속도만큼 진행
			int queueSize = progressQueue.size();
			for (int i = 0; i < queueSize; i++)
			{
				int currentProgress = progressQueue.front();
				progressQueue.pop();
				int currentSpeed = speedQueue.front();
				speedQueue.pop();

				currentProgress += currentSpeed; // 속도만큼 진행

				// 다시 큐에 삽입 (100% 완료되지 않은 작업들만)
				if (currentProgress < 100)
				{
					progressQueue.push(currentProgress);
					speedQueue.push(currentSpeed);
				}
			}

			// 완료된 작업들을 체크
			while (!progressQueue.empty() && progressQueue.front() >= 100)
			{
				progressQueue.pop();
				speedQueue.pop();
				nCount++; // 완료된 작업 개수 증가
			}

			if (nCount > 0)
			{
				answer.push_back(nCount); // 완료된 작업 수를 저장
			}
		}

		return answer;
	}
}
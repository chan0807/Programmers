#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace ��ɰ��� {
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

		//Queue Ȱ��
		queue<int> progressQueue;
		queue<int> speedQueue;

		// progresses�� speeds�� ���� ť�� ����
		for (int i = 0; i < progresses.size(); i++)
		{
			progressQueue.push(progresses[i]);
			speedQueue.push(speeds[i]);
		}

		while (!progressQueue.empty())
		{
			// ��� �۾��� ���� �Ϸ�ġ ���� ��Ȳ�� ������Ʈ
			int nCount = 0;

			// �� �۾��� �ӵ���ŭ ����
			int queueSize = progressQueue.size();
			for (int i = 0; i < queueSize; i++)
			{
				int currentProgress = progressQueue.front();
				progressQueue.pop();
				int currentSpeed = speedQueue.front();
				speedQueue.pop();

				currentProgress += currentSpeed; // �ӵ���ŭ ����

				// �ٽ� ť�� ���� (100% �Ϸ���� ���� �۾��鸸)
				if (currentProgress < 100)
				{
					progressQueue.push(currentProgress);
					speedQueue.push(currentSpeed);
				}
			}

			// �Ϸ�� �۾����� üũ
			while (!progressQueue.empty() && progressQueue.front() >= 100)
			{
				progressQueue.pop();
				speedQueue.pop();
				nCount++; // �Ϸ�� �۾� ���� ����
			}

			if (nCount > 0)
			{
				answer.push_back(nCount); // �Ϸ�� �۾� ���� ����
			}
		}

		return answer;
	}
}
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	priority_queue<int, vector<int>, greater<>> pq;

	for (const auto& operation : operations) {
		stringstream ss(operation);
		string op;
		int num;
		ss >> op >> num;

		if (op == "I") {
			pq.push(num);
		}
		else if (op == "D") {
			if (pq.empty()) continue;

			if (num == 1) {
				priority_queue<int> temp;
				while (pq.size() > 1) {
					temp.push(pq.top());
					pq.pop();
				}
				pq.pop();
				while (!temp.empty()) {
					pq.push(temp.top());
					temp.pop();
				}
			}
			else if (num == -1) {
				pq.pop();
			}
		}
	}

	vector<int> temp;
	while (!pq.empty()) {
		temp.push_back(pq.top());
		pq.pop();
	}

	if (temp.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(temp.back());
		answer.push_back(temp.front());
	}

	return answer;
}
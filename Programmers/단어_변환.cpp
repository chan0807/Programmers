#include <string>
#include <vector>
#include <queue>

using namespace std;
namespace changeWord {
	bool changeable(const queue<string>& beginWords, const string& target) {

		if (beginWords.empty()) return false;

		queue<string> tempQueue = beginWords;
		while (!tempQueue.empty()) {
			if (tempQueue.front() == target) {
				return false;
			}
			tempQueue.pop();
		}
		
		string begin = beginWords.back();
		
		int diffCount = 0;
		for (size_t i = 0; i < begin.length(); ++i) {
			if (begin[i] != target[i]) {
				++diffCount;
				
				if (diffCount > 1) 
					return false;			
			}
		}
		return diffCount == 1;
	}

	int solution(string begin, string target, vector<string> words) {		
		queue<queue<string>> qq;
		queue<string> q;
		q.push(begin);
		qq.push(q);

		int steps = 0;
		while (!qq.empty()) {
			int size = qq.size();
			for (int i = 0; i < size; ++i) {
				for (const auto& afterWord : words) {
					auto beginWords = qq.front();
					if (changeable(beginWords, afterWord)) {
						if (afterWord == target) return ++steps;
						beginWords.push(afterWord);			
						qq.push(beginWords);
					}
				}
				qq.pop();
			}
			steps++;
		}
		return 0;
	}
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

namespace 큰수만들기 {
	string solution(string number, int k) {
		string answer = "";
		stack<char> stack;

		for (char digit : number) {
			while (!stack.empty() && stack.top() < digit && k > 0) {
				stack.pop();
				--k;
			}
			stack.push(digit);
		}

		while (k > 0) {
			stack.pop();
			--k;
		}

		while (!stack.empty()) {
			answer += stack.top();
			stack.pop();
		}

		reverse(answer.begin(), answer.end());
		return answer;
	}
}
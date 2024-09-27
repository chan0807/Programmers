#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> v_stack;
    for (int i = 0; i < progresses.size(); i++)
    {
        int time = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) time += 1;

        if (v_stack.size() == 0) { v_stack.push_back(time); }
        else if (v_stack[0] < time) {
            answer.push_back(v_stack.size());
            v_stack.clear();
            v_stack.push_back(time);
        }
        else v_stack.push_back(time);
    }
    if (v_stack.size() != 0)
        answer.push_back(v_stack.size());
    return answer;
}
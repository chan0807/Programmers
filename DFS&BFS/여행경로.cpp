#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> real_answer;


void dfs(int start_index, vector<int> visit, vector<vector<string>> tickets, vector<string> answer, int n)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        vector<int> temp_visit(visit);
        vector<string> temp_answer(answer);
        if (tickets[start_index][1] == tickets[i][0] && visit[i] == 0)
        {
            temp_visit[i] = 1;
            temp_answer.push_back(tickets[i][0]);
            if (n + 1 == tickets.size())
            {
                temp_answer.push_back(tickets[i][1]);

                real_answer.push_back(temp_answer);
                return;
            }
            dfs(i, temp_visit, tickets, temp_answer, n + 1);
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {


    for (int i = 0; i < tickets.size(); i++)
    {
        vector<string> answer;
        vector<int> visit(tickets.size(), 0);
        if (tickets[i][0] == "ICN")
        {
            visit[i] = 1;
            answer.push_back("ICN");
            dfs(i, visit, tickets, answer, 1);
        }
    }

    sort(real_answer.begin(), real_answer.end(), [](const vector<string>& a, const vector<string>& b) {
        return a < b;
        });
    return real_answer[0];
}
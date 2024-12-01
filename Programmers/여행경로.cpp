#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace 여행경로 {
    vector<string> answer;  
    string result = "Z";
    vector<bool> isUsed;

    void dfs(int count, string start, vector<vector<string>>& tickets, string path) {
        if (count == tickets.size()) {
            if (result > path) result = path;
            return;
        }
        for (int i = 0; i < tickets.size(); i++) {
            if (!isUsed[i] && tickets[i][0] == start) {
                isUsed[i] = true;
                dfs(count + 1, tickets[i][1], tickets, path + " " + tickets[i][1]);
                isUsed[i] = false;
            }
        }
    }

    vector<string> solution(vector<vector<string>> tickets) {
        isUsed = vector<bool>(tickets.size(), false);
        dfs(0, "ICN", tickets, "ICN");
        vector<string> finalAnswer;
        size_t pos = 0;
        while ((pos = result.find(' ')) != string::npos) {
            finalAnswer.push_back(result.substr(0, pos));
            result.erase(0, pos + 1);
        }

        finalAnswer.push_back(result);

        return finalAnswer;
    }
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

namespace 여행경로 {
    // BFS
    //vector<string> bfs(const vector<vector<string>>& tickets)
    //{
    //    int nTicketSize = tickets.size();
    //    vector<bool> used(nTicketSize, false);
    //    vector<string> path = { "ICN" };

    //    while (path.size() <= nTicketSize) {
    //        string current = path.back();

    //        vector<vector<string>> starts;
    //        for (int i = 0; i < tickets.size(); i++) {
    //            if (!used[i] && tickets[i][0] == current) {
    //                starts.push_back(tickets[i]);
    //            }
    //        }

    //        sort(starts.begin(), starts.end(), [](const vector<string>& a, const vector<string>& b) {
    //            return a[1] < b[1];
    //            });

    //        if (!starts.empty()) {
    //            vector<string> selected = starts[0];
    //            for (int i = 0; i < tickets.size(); i++) {
    //                if (!used[i] && tickets[i] == selected) {
    //                    used[i] = true;
    //                    break;
    //                }
    //            }

    //            path.push_back(selected[1]);
    //        }
    //        else {
    //            break;
    //        }
    //    }

    //    return path;
    //}

    //vector<string> solution(vector<vector<string>> tickets) {
    //    vector<string> answer;
    //    answer = bfs(tickets);
    //    
    //    return answer;
    //}

    vector<string> path;
    bool dfs(const string& current, vector<vector<string>>& tickets, vector<bool>& used) 
    {
        if (path.size() == tickets.size() + 1) 
        {
            return true;
        }

        for (int i = 0; i < tickets.size(); i++) 
        {
            if (!used[i] && tickets[i][0] == current) 
            {
                used[i] = true;
                path.push_back(tickets[i][1]);

                if (dfs(tickets[i][1], tickets, used)) 
                {
                    return true;
                }

                used[i] = false;
                path.pop_back();
            }
        }

        return false;
    }

    vector<string> solution(vector<vector<string>> tickets) 
    {
        sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b) 
        {
            return a[1] < b[1];
        });

        vector<bool> used(tickets.size(), false);
        path.push_back("ICN");
        dfs("ICN", tickets, used);

        return path;
    }

}
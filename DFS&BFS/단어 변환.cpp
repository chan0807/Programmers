#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

bool is_ChangeAble(const string& a, const string& b)
{
    int count =0;
    for(int i =0;i< a.size();i++)
    {
        if(a[i] != b[i])
        {
            count++;
            if(count >1) return false;
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> BFS;
    BFS.push({begin, 0});

    while (!BFS.empty()) {
        auto [word, cnt] = BFS.front();
        BFS.pop();

        if (word == target) {
            return cnt;
        }

        for (int j = 0; j < words.size(); ++j) {
            if (visited[j]) continue;
            if(!is_ChangeAble(words[j], word)) continue;
            visited[j] = true;
            BFS.push({words[j], cnt + 1});
        }
    }
    return 0;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

namespace 단어변환 {
    int bfs(string& begin, string& target, const vector<string>& words)
    {
        int nWordsSize = words.size();
        vector<bool> used(vector<bool>(nWordsSize, false));

        queue<pair<string, int>> q;
        q.push({ begin, 0 });

        while (!q.empty()) {
            pair<string, int> current = q.front();
            string sCurrent = current.first;
            int nChangeCount = current.second;
            q.pop();

            if (sCurrent == target) {
                return nChangeCount;
            }

            for (int i = 0; i < nWordsSize; ++i) {
                if (!used[i]) {
                    int nDiffCount = 0;

                    for (int j = 0; j < sCurrent.size(); ++j) {
                        if (sCurrent[j] != words[i][j]) {
                            nDiffCount++;
                        }
                    }

                    if (nDiffCount == 1) {
                        used[i] = true;
                        q.push({ words[i], nChangeCount + 1 });
                    }
                }
            }
        }
    }

    int solution(string begin, string target, vector<string> words) {

        if (find(words.begin(), words.end(), target) == words.end()) {
            return 0;
        }

        return bfs(begin, target, words);
    }
}
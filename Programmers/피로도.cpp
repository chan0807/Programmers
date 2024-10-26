#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

namespace ÇÇ·Îµµ {
    void GoAllDungeon(const vector<vector<int>>& dungeons, int nCurrentK, vector<bool>& bUsed, int nResult, int& nMaxResult) {
        nMaxResult = max(nMaxResult, nResult);

        for (int i = 0; i < dungeons.size(); ++i) {
            if (!bUsed[i] && nCurrentK >= dungeons[i][0]) {
                bUsed[i] = true;
                GoAllDungeon(dungeons, nCurrentK - dungeons[i][1], bUsed, nResult + 1, nMaxResult);
                bUsed[i] = false;
            }
        }
    }

    int solution(int k, vector<vector<int>> dungeons) {
        int answer = -1;
        vector<bool> bUsed(dungeons.size(), false);

        GoAllDungeon(dungeons, k, bUsed, 0, answer);

        return answer;
    }
}
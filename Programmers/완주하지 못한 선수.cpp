#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

namespace 완주하지못한선수 {
    string solution(vector<string> participant, vector<string> completion) 
    {
        if (participant.size() == 1) return *(participant.begin());

        sort(participant.begin(), participant.end());
        sort(completion.begin(), completion.end());
        int i = 0;
        while (*(participant.begin() + i) == *(completion.begin() + i)) {
            i++;

        }
        return *(participant.begin() + i);
    }
}
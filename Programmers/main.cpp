#include <iostream>
#include <vector>

using namespace std;

namespace 여행경로 {
    vector<string> solution(vector<vector<string>> tickets);
}

int main()
{
    vector<vector<string>> tickets = {
     {"ICN", "NRT"},
     {"NRT", "ICN"},
     {"ICN", "KIX"},
     {"KIX", "NRT"}
    };

    vector<string> answer = 여행경로::solution(tickets);

    return 0;
}
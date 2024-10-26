#include <iostream>
#include <vector>

using namespace std;

namespace 피로도 {
    int solution(int k, vector<vector<int>> dungeons);
}

int main()
{
    vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };
    int k = 80;

    int answer = 피로도::solution(k, dungeons);

    return 0;
}
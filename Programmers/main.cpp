#include <iostream>
#include <vector>

using namespace std;

namespace 게임맵최단거리 {
    int solution(vector<vector<int>> maps);
}

int main()
{
    vector<vector<int>> maps ={
        {1,0,1,1,1},
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,1,1,0,1},
        {0,0,0,0,1}
    };
    int answer = 게임맵최단거리::solution(maps);

    return 0;
}
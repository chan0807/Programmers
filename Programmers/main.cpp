#include <iostream>
#include <vector>

using namespace std;

namespace 단속카메라 {
    int solution(vector<vector<int>> routes);
}

int main()
{
    int n = 4;
    vector<vector<int>> routes = {{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}};

    int answer = 단속카메라::solution(routes);

    return 0;
}
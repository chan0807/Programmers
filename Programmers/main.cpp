#include <iostream>
#include <vector>

using namespace std;

namespace 등굣길 {
    int solution(int m, int n, vector<vector<int>> puddles);
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { {2,2} };
    int answer = 등굣길::solution(m,n,puddles);

    return 0;
}
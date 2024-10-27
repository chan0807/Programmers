#include <iostream>
#include <vector>

using namespace std;

namespace 체육복 {
    int solution(int n, vector<int> lost, vector<int> reserve);
}
int main()
{
    int n = 6;
    vector<int> lost = { 1, 3 };
    vector<int> reserve = { 2,4 };

    int answer = 체육복::solution(n, lost, reserve);

    return 0;
}
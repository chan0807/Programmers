#include <string>
#include <vector>
#include <algorithm>
// #include <ranges>
using namespace std;

bool borrow(const vector<int>& reserve, vector<int>& checker, int& answer, int target_index)
{
    if(auto it = find(reserve.begin(), reserve.end(), target_index); it != reserve.end())
    {
        int checker_i = distance(reserve.begin(), it);
        if(checker[checker_i])
        {
            checker[checker_i] = false;
            answer++;
            return true;
        }
    }
    return false;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<int> checker (reserve.size(), true);
    for(auto idx = 0 ; idx < reserve.size(); ++idx)
    {
        if(auto it = find(lost.begin(), lost.end(), reserve[idx]); it != lost.end())
        {
            checker[idx] = false;
            lost.erase(it);
            answer++;
        }
    }
    for(int i : lost)
    {
        if(borrow(reserve, checker, answer, i-1) || borrow(reserve, checker, answer, i+1))
            continue;
    }

    return answer;
}

// int main()
// {
//     int n = 5;
//     vector<int> lost = {1,2,3,4,5};
//     vector<int> reserve = {2,4,5};
//     int ans = solution(n, lost, reserve);

//     return 0;
// }
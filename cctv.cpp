#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int current_st = routes[0][0]; int current_end = routes[0][1];
    answer++;
    for(auto route: routes)
    {
        if(current_end >= route[1])
        {
            current_end = route[1];
            continue;
        }

        if(current_end < route[0])
        {
            current_end = route[1];
            answer++;
            continue;
        }
    }

    return answer;
}

// int main()
// {
//     vector<vector<int>> routes = {{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}};
//     int ans = solution(routes);
//     return 0;
// }
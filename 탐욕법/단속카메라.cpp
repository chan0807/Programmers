#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
     int answer = 1; //무조건 한대 이상
    sort(routes.begin(),routes.end(), [](const auto& a, const auto& b){ return a[0] < b[0];});
    
    int end =  routes[0][1];
    
    for(int i = 1;i < routes.size();i++)
    {
        if( end >= routes[i][0]) //겹침 
        {
            end = min(routes[i][1],end);
        }
        else{ // 안겹침
            answer++;
            end = routes[i][1];
        }
    }
    
    return answer;
}
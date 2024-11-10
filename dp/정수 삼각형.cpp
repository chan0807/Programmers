#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=triangle[i].size()-1;j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
        }
    }
    
    answer = *max_element(dp[ triangle.size() - 1], dp[ triangle.size() - 1] + triangle[ triangle.size() - 1].size());
    
    return answer;
    
}

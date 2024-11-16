#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 요건 시간 초과 ㅠ
void dp(int i, int j, int& count, vector<vector<int>>& memo, int m, int n)
{
    if(i == m-1 && j == n-1)
    {
        count++;
        return;
    }
    if(i >= m || j >= n)
        return;
    if(memo[j][i] == -1)
        return;
    dp(i, j+1, count, memo, m, n);
    dp(i+1, j, count, memo, m, n);
}


int solution(int m, int n, vector<vector<int>> puddles) {
    int MOD = 1000000007;
    vector<vector<int>> memo (n+1, vector<int>(m+1,0));
    for(auto puddle: puddles) {
        memo[puddle[1]][puddle[0]] = -1;
    }
    memo[1][1] = 1;
    for(int i=1; i <= n; i++)
    {
        for(int j=1; j <= m; j++)
        {
            if(memo[i][j] == -1)
            {
                memo[i][j]++;
                continue;
            }
            memo[i][j] += (memo[i-1][j] + memo[i][j-1]) % MOD;
        }
    }
    return memo[n][m];
}

// int main()
// {
//     int ans = solution(4,3, {{2,2}});
//     return 0;
// }
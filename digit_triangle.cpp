#include <string>
#include <vector>

using namespace std;



int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    for(int i=n-1; i > 0; i--)
    {
        int len = triangle[i].size();

        for(int j=0; j < len-1; j++)
        {
            triangle[i-1][j] += triangle[i][j] < triangle[i][j+1] ? triangle[i][j+1] : triangle[i][j];
        }
    }

    return triangle[0][0];
}

// int main()
// {
//     vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
//     int ans = solution(triangle);
//     return 0;
// }
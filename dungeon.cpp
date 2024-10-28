#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void explore(int& current_k, int& success, const vector<int>& dungeon) {
    success++;
    current_k -= dungeon[1];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    vector<int> indices(dungeons.size());
    iota(indices.begin(), indices.end(), 0);

    do{
        int current_k = k;
        int success = 0;
        for(int index : indices)
        {
            if(dungeons[index][0] > current_k)
                break;
            explore(current_k, success, dungeons[index]);
        }
        answer = max(answer, success);
    }
    while(next_permutation(indices.begin(), indices.end()));

    return answer;
}

// int main()
// {
//     int k = 80;
//     vector<vector<int>> dungeons = {{80,20}, {50,40},{30,10}};
//     int ans = solution(k, dungeons);
//     return 0;
// }
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers, int target) {
    vector<int> bfs {0};
    for(auto number: numbers)
    {
        vector<int> sub_bfs;
        for(auto node: bfs)
        {
            sub_bfs.push_back(node + number);
            sub_bfs.push_back(node - number);
        }
        bfs = sub_bfs;
    }
    return count(bfs.begin(), bfs.end(), target);
}


// int main()
// {
//     int ans = solution({4, 1, 2, 1}, 4);
//     return 0;
// }
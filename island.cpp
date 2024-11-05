#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findRoot(vector<int>& island, int n)
{
    if(island[n] == n) return n;
    return findRoot(island, island[n]);
}

void unite(vector<int>& island, int newRoot, int n)
{
    if(island[n] == n) {island[n] = newRoot; return;}
    unite(island, newRoot, island[n]);
    island[n] = newRoot;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){ return a[2] < b[2]; });
    
    vector<int> island(n);
    iota(island.begin(), island.end(), 0);

    for(auto& cost : costs)
    {
        if(auto root = findRoot(island, cost[0]); root != findRoot(island, cost[1]))
        {
            unite(island, root, cost[1]);
            answer += cost[2];
        }
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> costs = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {0, 2, 3}, {1, 3, 4}};
    int ans = solution(4, costs);
    return 0; 
}
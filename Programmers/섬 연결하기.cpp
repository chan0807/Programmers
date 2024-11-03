#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

namespace º∂ø¨∞·«œ±‚ {
    int findParent(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = findParent(parent, parent[x]);
        }
        return parent[x];
    }

    void setUnion(vector<int>& parent, vector<int>& rank, int first, int second) {
        int rootFirst = findParent(parent, first);
        int rootSecond = findParent(parent, second);

        if (rootFirst != rootSecond) {
            if (rank[rootFirst] > rank[rootSecond]) {
                parent[rootSecond] = rootFirst;
            }
            else if (rank[rootFirst] < rank[rootSecond]) {
                parent[rootFirst] = rootSecond;
            }
            else {
                parent[rootSecond] = rootFirst;
                rank[rootFirst]++;
            }
        }
    }

    int solution(int n, vector<vector<int>> costs) {
        int answer = 0;

        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
            });

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // {0,1,2,3,...,n}

        vector<int> rank(n, 0);

        int nCount = 0;
        for (const auto& cost : costs) {
            int first = cost[0];
            int second = cost[1];
            int weight = cost[2];

            if (findParent(parent, first) != findParent(parent, second)) {
                setUnion(parent, rank, first, second);
                answer += weight;
                nCount++;

                if (nCount == n - 1) {
                    break;
                }
            }
        }

        return answer;
    }
}
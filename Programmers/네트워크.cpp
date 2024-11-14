#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
namespace network {

	int mergeNode(const int totalCnt, vector<set<int>>& nodes) {
		for (int i = 0; i < totalCnt; ++i) {
			vector<int> nodeIdx;
			for (auto node = nodes.begin(); node != nodes.end(); ++node) {
				if (node->find(i) != node->end()) {
					nodeIdx.push_back(node - nodes.begin());
				}
			}

			set<int> mergedNode;
			for (int idx : nodeIdx) {
				mergedNode.insert(nodes[idx].begin(), nodes[idx].end());
			}
								
			for (auto it = nodeIdx.rbegin(); it != nodeIdx.rend(); ++it) {
				nodes.erase(nodes.begin() + *it);
			}

			nodes.push_back(mergedNode);
		}

		return nodes.size();
	}

	int solution(int n, vector<vector<int>> computers) {
		const int iCntComputer = computers.size();

		vector<set<int>> nodes(iCntComputer);

		for (int i = 0; i < iCntComputer; ++i)
		{
			for (int j = 0; j < iCntComputer; ++j)
			{
				if (computers[i][j])
				{
					nodes[i].insert(j);
				}
			}
		}

		return mergeNode(iCntComputer, nodes);
	}
}
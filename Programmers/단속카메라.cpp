#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace 단속카메라 {
	int solution(vector<vector<int>> routes) 
	{
		int answer = 0;

		sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
			const int rout1 = a[0];
			const int rout2 = b[0];
			return rout1 < rout2;
			});

		vector<vector<int>> minRoutes;
		minRoutes.push_back(routes[0]);

		for (const auto route : routes) 
		{
			bool isExist = false;
			for (auto& minRoute : minRoutes) 
			{
				if ((route[0] <= minRoute[1] && route[0] >= minRoute[0]) ||
					(route[1] <= minRoute[1] && route[1] >= minRoute[0])) 
				{
					minRoute[0] = max(route[0], minRoute[0]);
					minRoute[1] = min(route[1], minRoute[1]);
					isExist = true;
					break;
				}
			}

			if (!isExist)
			{
				minRoutes.push_back(route);
			}
		}

		answer = minRoutes.size();

		return answer;
	}
}
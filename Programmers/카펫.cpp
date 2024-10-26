#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

namespace Ä«Æê {
    // Search Zero to All
    vector<int> solution1(int brown, int yellow) {
        vector<int> answer;

        int nTotal = brown + yellow;

        int x = 3;
        int y = 3;

        for (x = 3; x <= nTotal; x++)
        {
            for (y = 3; y <= x; y++)
            {
                if (x * y == nTotal)
                {
                    int nCalculatedBrown = 2 * x + 2 * (y - 2);

                    if (nCalculatedBrown == brown)
                    {
                        answer.push_back(x);
                        answer.push_back(y);
                        return answer;
                    }
                }
            }
        }
    }

    //Equation
    vector<int> solution2(int brown, int yellow) {
        vector<int> answer;

        double k = (1 + (double)brown / 4);
        double kk = pow(k, 2);

        double dX = k + sqrt(kk - (brown + yellow));
        double dY = (brown + yellow) / dX;

        answer.push_back((int)dX);
        answer.push_back((int)dY);

        return answer;
    }
}


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

namespace 체육복 {
    void CalculateMax(vector<bool>& aHasStudent, vector<bool>& aReserveUsed, const vector<int>& reserve, int nInitialCount, int& nMaxResult) {
        nMaxResult = max(nMaxResult, nInitialCount);

        for (int i = 0; i < reserve.size(); ++i) {
            int num = reserve[i];

            if (num - 2 >= 0 && !aHasStudent[num - 2] && !aReserveUsed[i]) {
                aHasStudent[num - 2] = true;   
                aReserveUsed[i] = true;        
                CalculateMax(aHasStudent, aReserveUsed, reserve, nInitialCount + 1, nMaxResult);
                aHasStudent[num - 2] = false;  
                aReserveUsed[i] = false;    
            }

            if (num < aHasStudent.size() && !aHasStudent[num] && !aReserveUsed[i]) {
                aHasStudent[num] = true;       
                aReserveUsed[i] = true;        
                CalculateMax(aHasStudent, aReserveUsed, reserve, nInitialCount + 1, nMaxResult);
                aHasStudent[num] = false;     
                aReserveUsed[i] = false;     
            }
        }
    }

    //완전탐색
    int solution1(int n, vector<int> lost, vector<int> reserve) {
        int answer = 0;

        vector<bool> aHasStudent(n, true);
        vector<int> common;

        sort(lost.begin(), lost.end());
        sort(reserve.begin(), reserve.end());

        set_intersection(lost.begin(), lost.end(), reserve.begin(), reserve.end(), back_inserter(common));

        for (int num : lost) {
            if (find(common.begin(), common.end(), num) == common.end()) {
                aHasStudent[num - 1] = false;
            }
        }

        int nInitialCount = count(aHasStudent.begin(), aHasStudent.end(), true);

        vector<int> newReserve;
        set_difference(reserve.begin(), reserve.end(), lost.begin(), lost.end(), back_inserter(newReserve));
        reserve = newReserve;

        vector<bool> aReserveUsed(reserve.size(), false);
        CalculateMax(aHasStudent, aReserveUsed, reserve, nInitialCount, answer);

        return answer;
    }

    //탐욕법
    int solution2(int n, std::vector<int> lost, std::vector<int> reserve) {
        int answer = 0;

        sort(lost.begin(), lost.end());
        sort(reserve.begin(), reserve.end());

        for (int i = 0; i < reserve.size(); ++i) {
            for (int j = lost.size() - 1; j >= 0; --j) {
                if (reserve[i] == lost[j]) {
                    reserve[i] = -1;
                    lost.erase(lost.begin() + j);
                    break;
                }
            }
        }

        vector<bool> hasUniform(n, true);
        for (int num : lost) {
            hasUniform[num - 1] = false;
        }

        for (int num : reserve) {
            if (num == -1) continue;
            if (num - 1 > 0 && !hasUniform[num - 2]) {
                hasUniform[num - 2] = true;
            }
            else if (num < n && !hasUniform[num]) {
                hasUniform[num] = true;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (hasUniform[i]) {
                ++answer;
            }
        }

        return answer;
    }
}
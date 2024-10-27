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

    int solution(int n, vector<int> lost, vector<int> reserve) {
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
}
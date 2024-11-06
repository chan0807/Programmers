#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace 단속카메라 {
    int solution(vector<vector<int>> routes) {
        int answer = 0;

        sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
            });

        int camera_position = -30001;

        for (const auto& route : routes) {
            if (camera_position < route[0]) {
                camera_position = route[1];
                answer++;
            }
        }
        
        return answer;
    }
}
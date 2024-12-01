#include <string>
#include <vector>

using namespace std;

namespace 입국심사 {
    long long solution(int n, vector<int> times) {
        long long min = 0, max = (long long)times.back() * n;
        long long answer = max;
        
        while (min <= max) {
            long long mid = (min + max) / 2;
            long long people = 0;
            
            for (int time : times) {
                people += mid / time;
            }
            
            if (people >= n) {
                answer = mid;
                max = mid - 1;
            } else { 
                min = mid + 1;
            }
        }
        
        return answer;
    }
}

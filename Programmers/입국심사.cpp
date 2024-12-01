#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace 입국심사 {
    long long solution(int n, vector<int> times) 
    {
        sort(times.begin(), times.end());

        // 최소 시간
        long long left = 1; 

        // 최대 시간
        long long right = (long long)times.back() * n; 

        // 최대 시간을 정답으로
        long long answer = right;
        while (left <= right) 
        {
            // 현재 시간 mid
            long long mid = (left + right) / 2; 
            long long people = 0;

            // mid 시간 동안 처리할 수 있는 인원 계산
            for (const auto& time : times) 
            {
                people += mid / time; // 한 심사관이 처리할 수 있는 사람 수
                if (people >= n) break; // n명을 초과하면 더 계산할 필요 없음
            }

            // mid 시간에 모든 사람을 처리할 수 있다면
            if (people >= n) 
            {
                answer = mid; // 정답 갱신
                right = mid - 1; // 더 적은 시간으로도 가능한지 탐색
            }
            else 
            {
                left = mid + 1; // 시간이 부족하므로 더 많은 시간을 탐색
            }
        }

        return answer;
    }
}
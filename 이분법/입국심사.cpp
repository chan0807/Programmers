#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min_time = *min_element(times.begin(),times.end());
    long long start = min_time;
    long long end = min_time * n ;
    
    while(start <= end)
    {
        int count = 0;
        long long mid = (start+end) /2;
        for(const auto& time : times)
     {
         count += mid / time;
         if(count >= n){
             answer = mid;
             end = mid - 1;
             break;
         }
     }
       if(count < n){ start  = mid + 1;}
    }
    
    return answer;
}
    
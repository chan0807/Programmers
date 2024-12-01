#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    sort(times.begin(), times.end());
    unsigned long long min = 1;
    unsigned long long max = times.back() * n;
    while(min <= max)
    {
        unsigned long long possiblePassensers = 0;
        unsigned long long mid = (min+max)/2;
        for(const unsigned long long& time : times)
        {
            possiblePassensers += mid/time;
        }

        if(possiblePassensers >= n)
        {
            max = mid -1;
            answer = mid;
        }
        else
        {
            min = mid+1;
        }
    }
    
    return answer;
}

int main()
{

    solution(6, {7,10});
    return 0;
}
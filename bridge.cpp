#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checker(const vector<int>& stones, int k)
{
    int count = 0;
    for(int i =0; i < stones.size(); i++)
    {
        if(stones[i] == 0)
            count++;
        else
            count = 0;
        if(count >= k )
            return true;
    }
    return false;
}

int naive_solution(vector<int> stones, int k) {
    int answer = 0;
    while(!checker(stones, k))
    {
        transform(stones.begin(), stones.end(), stones.begin(), [](int s)
        {
            return s-1 < 0? 0: s-1;
        });
        answer++;
    }

    return answer;
}

////////////////////////////////////////////////////


int big_n_solution(vector<int> stones, int k) {
    int answer = __INT_MAX__;
    int size = stones.size();
    for(int i =0; i < size-k; i++)
    {
        auto maxval = *max_element(stones.begin()+i, stones.begin()+i+k);
        answer = answer > maxval ? maxval : answer;
    }
    return answer;
}
/////////////////////////////////////////////////////

bool check(const vector<int>& stones, int candidate, int k)
{
    int size = stones.size();
    int count = 0 ;
    for(int i =0; i < size; i++)
    {
        if(stones[i] <= candidate )
            count++;
        else
            count = 0;
        if(count ==  k)
            return true;    
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start =0, end = *max_element(stones.begin(), stones.end());

    while(start <= end)
    {
        int candidate = (start+end)/2;
        if(check(stones, candidate, k))
            end = candidate-1;
        else
            start = candidate+1;
    }

    return start;
}

// int main()
// {
//     solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3);
//     return 0;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check(int index ,const vector<int>& copy_stones,const vector<int>& stones,int k)
{
     int count = 0;
     for(auto& stone : stones)
        {
            if(stone <= copy_stones[index]) 
            {
                count++;
                 if(count >= k) return true;
            }
            else
            { count =0;}
        }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer=0;

    vector<int> copy_stones(stones.begin(),stones.end());
     sort(copy_stones.begin(), copy_stones.end());
    copy_stones.erase(unique(copy_stones.begin(), copy_stones.end()), copy_stones.end());
  
    int start = 0;
    int end = copy_stones.size();
    int mid;
    while(start <= end)
    {
        mid = (start + end)/2;
        if(check(mid, copy_stones ,stones,k))
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }

    }
    return copy_stones[start];
}
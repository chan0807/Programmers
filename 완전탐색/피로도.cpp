#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    sort(dungeons.begin(),dungeons.end());
    do{
        int crr_k = k;
        int count=0;
        for(const auto& d : dungeons)
        {
            if(d[0] <=crr_k){
            crr_k -=d[1]; 
            count++;
            }
        }
        if(count >answer) answer = count;
    }while(next_permutation(dungeons.begin(),dungeons.end()));
        
    return answer;
}
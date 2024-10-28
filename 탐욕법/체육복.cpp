#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int count = 0; // 빌려준 횟수
    sort(lost.begin(),lost.end()); sort(reserve.begin(),reserve.end());

    for(int j=lost.size()-1;j>=0;--j){
        for(int i=0;i<reserve.size();i++){
            if(reserve[i] ==lost[j])
                {
                     reserve.erase(reserve.begin()+i);
                     lost.erase(lost.begin()+j);
                     break;
                }
        }
    }
    
    for(int i = 0; i< lost.size();i++)
    {
          for(int j=0;j<reserve.size();j++){
            if(reserve[j] == lost[i]-1 ||reserve[j] == lost[i]+1 )
            {
               reserve.erase(reserve.begin()+j);
                count++;
                break;
                
            }
        }
    }
    
    return n - lost.size()+ count;
}
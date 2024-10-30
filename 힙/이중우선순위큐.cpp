#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(const auto& str : operations)
    {
         int num =  stoi(str.substr(2));
        switch(str[0]){
            case 'I' :
                {
                    
                    answer.push_back(num);
                    break;
                }
            case 'D':
                {
                    if(answer.empty()) break;
                      sort(answer.begin(),answer.end());
                    if(num == -1){
                      answer.erase(answer.begin());
                    }
                    else{
                    answer.erase(answer.end()-1);
                    }
                      break;
                }
        }
    }
      sort(answer.begin(),answer.end());
   return  answer.empty() ?  vector<int>({0,0}) :   vector<int>({answer[answer.size()-1], answer[0]}) ;
}
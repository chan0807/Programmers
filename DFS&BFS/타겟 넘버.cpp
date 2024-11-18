#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(const vector<int>& numbers,int minusCount,int plusCount,int target)
{
    int count =0;
    string str = "";
    for(int i =0;i< plusCount;i++) str += "+";
    for(int i =0;i<minusCount;i++) str += "-";
    
    do{
        int res = 0;
        
       for(int i=0;i< numbers.size();i++)
       {
           if(str[i] == '-')res -=numbers[i];
           if(str[i] == '+')res +=numbers[i];
       }
        if(res ==target) count++;
    }while(next_permutation(str.begin(),str.end()));
    
    return count ;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    for(int i=0;i< numbers.size();i++)
    {
       answer+= dfs(numbers,numbers.size()-i,i,target);
    }
    
    return answer;
}
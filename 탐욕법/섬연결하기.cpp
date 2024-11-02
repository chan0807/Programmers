#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0;
    vector<pair<int, int>> dic_people;
    sort(people.begin(),people.end());
       for(int i =people.size()-1 ;i>=0;--i){
           if(i == front) {answer++; break;} //라스트 원
           if(i < front) break; 
           if(people[front] + people[i] <= limit){ // 같이 탐
             front++;
             answer++;
           }
           else{ //덩치가 탐 
                answer++;
           }
       }
    return answer;
}
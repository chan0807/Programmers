#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(3,0);
    vector<int> x = {1,2,3,4,5};
    vector<int> y = {2,1,2,3,2,4,2,5};
    vector<int> z = {3,3,1,1,2,2,4,4,5,5};

    for(int i=0; i < answers.size(); i++)
    {
        if(answers[i] == x[i%5]) answer[0]++;   
        if(answers[i] == y[i%8]) answer[1]++;   
        if(answers[i] == z[i%10]) answer[2]++;   
    }
    
    int maxN = *max_element(answer.begin(), answer.end());
    vector<int> ans;
    if(answer[0] == maxN) ans.push_back(1);
    if(answer[1] == maxN) ans.push_back(2);
    if(answer[2] == maxN) ans.push_back(3);
    sort(ans.begin(), ans.end());
    
    return ans;
}

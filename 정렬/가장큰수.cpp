#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v_str;
     for(const auto& n :numbers ){
        v_str.push_back(to_string(n));
    }
   sort(v_str.begin(),v_str.end(), [](string a,string b){
       return a+b > b+a;
   });
    
    for(const auto& s :v_str ){
        answer += s;
    }
    if(answer[0] == '0') answer= "0";
    return answer;
}
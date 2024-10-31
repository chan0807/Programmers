#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    int remove = k;
    int finish = number.length() - k;
    string answer = "";
    for(auto d: number)
    {
        while(!answer.empty() && remove > 0 && answer.back() < d)
        { answer.pop_back(); remove--; }
        answer.push_back(d);
    }    
    while(remove > 0) {answer.pop_back(); remove--;} 
    return answer;
}

int main()
{

    auto res = solution("54321", 4);
    return 0;
}
#include <string>

using namespace std;

namespace 큰수만들기 {
    string solution(string number, int k) {
        string answer;

        for (char num : number) {
            while (!answer.empty() && answer.back() < num && k > 0) {
                answer.pop_back();
                k--;
            }
            answer.push_back(num);
        }
     
        answer.resize(answer.size() - k);

        return answer;
    }
}
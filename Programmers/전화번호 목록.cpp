#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

namespace 전화번호목록 {
    bool solution(vector<string> phone_book) {
        bool answer = true;

        // 해시 활용
        unordered_map<string, int> prefixMap;

        for (const string& number : phone_book)
        {
            prefixMap[number] = 1;
        }

        // 각 번호의 접두사 여부 확인
        for (const string& number : phone_book)
        {
            for (int i = 1; i <= number.length(); ++i)
            {
                string prefix = number.substr(0, i);
                if (prefixMap.find(prefix) != prefixMap.end() && prefix != number)
                {
                    answer = false;
                }
            }
        }

        return answer;
    }
}
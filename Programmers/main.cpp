#include <iostream>
#include <vector>

using namespace std;

namespace 단어변환 {
    int solution(string begin, string target, vector<string> words);
}

int main()
{
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    int answer = 단어변환::solution(begin, target, words);

    return 0;
}
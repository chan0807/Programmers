#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Info
{
    string word;
    int count =0;
};
int N;
bool isConvertable(const string& src, const string& dst){
    int count=0;    
    for(int i = 0; i < N; ++i)
    {
        count += src[i] != dst[i] ? 1 : 0;
        if(count > 1)
            return false;
    }
    if(count == 1)
        return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    N = words[0].size();
    vector<bool> checker(words.size(), false);
    queue<Info> info;
    info.push({begin, 0});
    while(!info.empty())
    {
        const auto& current = info.front();
        info.pop();
        if(current.word == target)
            return current.count;
        for(int i =0; i< words.size(); ++i)
        {
            if(!checker[i] && isConvertable(current.word, words[i]))
            {
                info.push({words[i], current.count+1});
                checker[i] = true;
            }
        }
    }

    return 0;
}

// int main()
// {
//     solution("hit","cog", {"hot", "dot", "dog", "lot", "log", "cog"});
//     return 0;
// }
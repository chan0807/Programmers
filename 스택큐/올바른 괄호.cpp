#include<string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> stc;

    for (const auto& c : s)
    {
        if (c == ')')
        {

            if (stc.empty()) return false;
            else  stc.pop();
        }
        else stc.push(c);

    }
    if (stc.size() != 0) return false;

    return true;
}
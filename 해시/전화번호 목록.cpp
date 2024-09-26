
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phoneBook) {

    unordered_map<string, bool> hash_map;
    for (auto v : phoneBook)
    {
        hash_map[v] = true;
    }

    for (auto str : phoneBook)
    {
        for (int i = 1; i < str.size(); i++)
        {
            if (hash_map[str.substr(0, i)]) return false;
        }
    }

    return true;
}
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
bool is_prime(int num)
{

    if (num == 1 || num == 0) return false;
    if (num == 2) return true;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<char> v_char;
    vector<string> v_numbers;
    set<int> s_numbers;
    for (const auto& n : numbers)
    {
        v_char.push_back(n);
    }
    sort(v_char.begin(), v_char.end());
    do {
        string str = "";
        for (int i = 0; i < v_char.size(); i++)
        {

            str += v_char[i];
            s_numbers.insert(stoi(str));
        }
        v_numbers.push_back(str);
    } while (next_permutation(v_char.begin(), v_char.end()));

    for (const auto& n : s_numbers)
    {
        if (is_prime(n)) answer++;
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <ranges>
#include <unordered_set>
using namespace std;
void print(vector<int> v)
{
    for(auto val : v)
    {
        cout << val;
    }
    cout << endl;;
}

bool isPrime(int num)
{
    if(num == 1 || num == 0) return false;
    const auto k = sqrt(num);
    for(int i =2; i <= k; ++i){ if(num%i == 0) return false; }
    return true;
}

int solution(string numbers)
{
    sort(numbers.begin(), numbers.end());

    vector<string> permuted;
    do{
        cout<< numbers << endl;
        permuted.push_back(numbers);
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    unordered_set<int> distinctNumbers;
    for_each(permuted.begin(), permuted.end(), [&distinctNumbers](const string&  candidate){
        for(int i =1; i <= candidate.size(); i++)
            {
                if(int digit = stoi(candidate.substr(0,i)); isPrime(digit))
                    distinctNumbers.insert(digit);
            }
    });
    return distinctNumbers.size();
}

// int main()
// {
//     string numbers = "011";
//     cout << solution(numbers);

//     return 0;
// }
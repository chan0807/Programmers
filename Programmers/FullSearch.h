#pragma once

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

//Carpet - 2: Search Zero to All
vector<int> FullSearchThree2(int brown, int yellow) {
    vector<int> answer;

    int nTotal = brown + yellow;

    int x = 3;
    int y = 3;

    for (x = 3; x <= nTotal; x++) 
    {
        for (y = 3; y <= x; y++) 
        {
            if (x * y == nTotal) 
            {
                int nCalculatedBrown = 2 * x + 2 * (y - 2);

                if (nCalculatedBrown == brown)
                {
                    answer.push_back(x);
                    answer.push_back(y);
                    return answer;
                }
            }
        }
    }
}

//Carpet - 1: equation
vector<int> FullSearchThree1(int brown, int yellow) {
    vector<int> answer;

    double k = (1 + (double)brown / 4);
    double kk = pow(k, 2);

    double dX = k + sqrt(kk - (brown + yellow));
    double dY = (brown + yellow) / dX;

    answer.push_back((int)dX);
    answer.push_back((int)dY);

    return answer;
}

//Find prime numbers func - Prime Check
int IsPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) 
        {
            return false;
        }
    }
    return true;
}

//Find prime numbers func - Generate All Numbers
void generateAllNumbers(const string& str, set<int>& allnumbers, string current, vector<bool>& used) 
{
    if (!current.empty()) 
    {
        allnumbers.insert(stoi(current));
    }

    for (int i = 0; i < str.size(); ++i) 
    {
        if (!used[i]) 
        {
            used[i] = true;
            generateAllNumbers(str, allnumbers, current + str[i], used); //recursive
            used[i] = false;
        }
    }
}

//Find prime numbers
int FullSearchTwo(string numbers) {
    int answer = 0;
    set<int> setAllNumbers;
    vector<bool> used(numbers.size(), false);

    generateAllNumbers(numbers, setAllNumbers, "", used);

    for (int number : setAllNumbers)
    {
        if (number > 1 && IsPrime(number))
        {
            answer++;
        }
    }

    return answer;
}

//Mock Exam
vector<int> FullSearchOne(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> result = {{0,1},{0,2},{0,3}}; // answerCount,Index

    vector<int> aOne = { 1,2,3,4,5 };
    vector<int> aTwo = { 2,1,2,3,2,4,2,5 };
    vector<int> aThree = { 3,3,1,1,2,2,4,4,5,5 };

    queue<int> qOne;
    queue<int> qTwo;
    queue<int> qThree;

    for (const auto& One : aOne)
    {
        qOne.push(One);
    }

    for (const auto& Two : aTwo)
    {
        qTwo.push(Two);
    }

    for (const auto& Three : aThree)
    {
        qThree.push(Three);
    }

    for (const auto& ans : answers)
    {
        int nOneAnswer = qOne.front();
        int nTwoAnswer = qTwo.front();
        int nThreeAnswer = qThree.front();

        qOne.pop();
        qTwo.pop();
        qThree.pop();

        if (nOneAnswer == ans)
        {
            result[0].first++;
        }

        if (nTwoAnswer == ans)
        {
            result[1].first++;
        }

        if (nThreeAnswer == ans)
        {
            result[2].first++;
        }

        qOne.push(nOneAnswer);
        qTwo.push(nTwoAnswer);
        qThree.push(nThreeAnswer);
    }

    sort(result.begin(), result.end(), [](pair<int, int> a, pair<int, int> b) 
        {
            if (a.first != b.first) 
            {
                return a.first > b.first;  // first ¢Ù
            }
            else 
            {
                return a.second < b.second; // second ¢Ö
            }
        });

    int nMax = result[0].first;

    for (const auto& re : result)
    {
        if (re.first != 0 && nMax <= re.first)
        {
            answer.push_back(re.second);
        }
    }

    return answer;
}
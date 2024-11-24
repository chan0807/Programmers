#include <string>
#include <vector>
#include <set>

using namespace std;

namespace 소수찾기 {
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

    int solution(string numbers) {
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
}
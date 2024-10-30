#include <iostream>
#include <vector>

using namespace std;

namespace 큰수만들기 {
    string solution(string number, int k);
}
int main()
{
    string number = "7541651";
    int k = 3;

    string answer = 큰수만들기::solution(number, k);

    return 0;
}
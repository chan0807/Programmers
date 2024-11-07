#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int n = people.size();
    vector<int> check(n, false);
    int end = n-1;
    for(int i =0; i < n; i++){
        if(check[i])
            continue;

        check[i]++;
        answer++;

        if(!check[end] && people[end] <= limit - people[i])
            check[end--]++;
    }
    return answer;
}

// int main()
// {
//     vector<int> people = {70, 50, 80, 50};
//     int ans = solution(people, 1);
//     return 0;
// }
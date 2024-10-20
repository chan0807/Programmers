#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> generated_numbers;

    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0, i));
            generated_numbers.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (int num : generated_numbers) {
        if (is_prime(num)) answer++;
    }

    return answer;
}
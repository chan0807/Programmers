#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace 체육복 {
	int solution(int n, vector<int> lost, vector<int> reserve) {
		vector<int> student(n, 1);

		for (int idx : reserve)
			student[idx - 1] += 1;

		for (int idx : lost)
			student[idx - 1] -= 1;

		for (int i = 0; i < n; i++) {
			if (student[i] != 2) continue;

			if (i > 0 && student[i - 1] == 0) {
				student[i - 1] += 1;
			}
			else if (i < n-1 && student[i + 1] == 0) {
				student[i + 1] += 1;
			}
		}

		return count_if(student.begin(), student.end(), [](int value) {
			return value >= 1;
			});
	}
}
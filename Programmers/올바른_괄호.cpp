#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<char> st;

	for (char ch : s)
	{
		if (ch == '(')
		{
			st.push(ch);
		}
		else if (ch == ')')
		{

			if (st.empty()) return false;

			st.pop();
		}
	}
	return st.empty();
}
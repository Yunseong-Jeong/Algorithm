#include <iostream>
#include <stack>
#include <string>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	char input;
	while (true)
	{
		string s = "";
		while (true)
		{
			scanf("%c", &input);
			if (input == '.')
			{
				s += input;
				break;
			}
			else if (input == '\n')
				continue;
			else
				s += input;
		}
		if (s == ".")
			return 0;
		else
		{
			stack<char> st;
			for (int i = 0; i < s.length(); i++)
			{
				if (s.at(i) == '.')
					break;
				else if (s.at(i) == '(' || s.at(i) == '[')
					st.push(s.at(i));
				else if (s.at(i) == ')')
				{
					if (st.empty() || st.top() != '(')
					{
						st.push(')');
						break;
					}
					else if (st.top() == '(')
						st.pop();
				}
				else if (s.at(i) == ']')
				{
					if (st.empty() || st.top() != '[')
					{
						st.push(']');
						break;
					}
					else if (st.top() == '[')
						st.pop();
				}
			}
			if (st.size())
				printf("no\n");
			else
				printf("yes\n");
		}
		
	}
}
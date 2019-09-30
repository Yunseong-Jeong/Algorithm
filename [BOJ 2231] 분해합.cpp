#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input;
	scanf("%d", &input);
	string s = to_string(input);
	int len = s.length();
	int result = 0;
	for (int i = input - len * 9; i <= input; i++)
	{
		int tmp = i;
		s = to_string(i);
		for (int j = 0; j < s.length(); j++)
		{
			tmp += s.at(j) - '0';
		}
		if (tmp == input)
		{
			result = i;
			break;
		}
	}
	printf("%d\n", result);
	return 0;
}
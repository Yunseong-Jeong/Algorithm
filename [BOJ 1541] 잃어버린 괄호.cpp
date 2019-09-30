#include <iostream>
#include <string>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool check = false;
	int result = 0;
	string tmp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == '+' || s.at(i) == '-' || i==s.length()-1)
		{
			if (i == s.length() - 1)
				tmp += s.at(i);
			if (check)
				result -= stoi(tmp);
			else
				result += stoi(tmp);
			tmp = "";
			if (s.at(i) == '-')
				check = true;
			continue;
		}
		else
			tmp += s.at(i);
	}
	printf("%d\n", result);
	return 0;
}
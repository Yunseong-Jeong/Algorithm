#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string p)
{
	string answer = "";
	if (p == "")
		return p;
	pair<int, int> total = make_pair(0, 0);
	pair<int, int> current = make_pair(0,0);
	for (int i = 0; i < p.length(); i++)
	{
		if (p.at(i) == '(')
			total.first++;
		else if (p.at(i) == ')')
			total.second++;
	}
	int index = 0;
	string u = "", v = "";
	while (index < p.length())
	{
		if (p.at(index) == '(')
			current.first++;
		else if (p.at(index) == ')')
			current.second++;
		if (current.first == current.second && (total.first - current.first) == (total.second - current.second))
		{
			u = p.substr(0, index + 1);
			v = p.substr(index + 1, p.length() - (index + 1));
			break;
		}
		index++;
	}
	
	string tmp_s = u;
	for (int i = 0; i < tmp_s.length(); i++)
	{
		if (tmp_s[i] == ')')
		{
			for (int j = i; j >= 0; j--)
			{
				if (tmp_s[j] == '(')
				{
					tmp_s.erase(i, 1);
					tmp_s.erase(j, 1);
					i = 0;
					break;
				}
			}
		}
	}
	v = solution(v);//3¹ø
	if (tmp_s != "")
	{
		string check = "(";
		check += v;
		check += ")";
		u.erase(0, 1);
		u.erase(u.length() - 1, 1);
		for (int i = 0; i < u.length(); i++)
		{
			if (u.at(i) == '(')
				check += ")";
			else if (u.at(i) == ')')
				check += "(";
		}
		answer = check;
	}
	else
		answer = u + v;
	return answer;
}

int main()
{
	string s;
	cin >> s;
	string result = solution(s);
	cout << result << endl;
	return 0;
}
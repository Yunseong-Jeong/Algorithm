#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s)
{
	int answer = s.length();
	int len = 1;
	while (len <= s.length())
	{
		vector<pair<string, int>> v;
		for (int i = 0; i < s.length(); i += len)
		{
			string tmp = "";
			if (i + len > s.length() - 1)
			{
				for (int j = i; j < s.length(); j++)
				{
					tmp += s.at(j);
				}

			}
			else
			{
				for (int j = i; j < i + len; j++)
				{
					tmp += s.at(j);
				}
			}
			if (v.size()&&v[v.size() - 1].first == tmp)
			{
				v[v.size() - 1].second++;
			}
			else
				v.push_back(make_pair(tmp, 1));
		}
		string tmp = "";
		for (int i = 0; i<v.size(); i++)
		{
			if(v[i].second != 1)
				tmp += to_string(v[i].second);
			tmp += v[i].first;
		}
		int tmp_len = tmp.length();
		answer = min(answer, tmp_len);
		len++;
	}
	return answer;
}

int main()
{
	string s;
	cin >> s;
	int result = solution(s);
	printf("%d\n", result);
	return 0;
}
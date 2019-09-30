#include <iostream>
#include <string>
#include <vector>

using namespace std;
void preprocessing(string s, int *p)
{
	s = " " + s;
	int s_index = 1;
	int c_index = 0;
	p[0] = 0;
	p[1] = 0;
	p[s.length()] = 0;
	while (s_index < s.length())
	{
		if (c_index == 0 || s[s_index] == s[c_index])
		{
			s_index++;
			c_index++;
			p[s_index] = c_index;
		}
		else
			c_index = p[c_index];
	}
}
vector<int> solution(vector<string> words, vector<string> queries)
{
	vector<int> answer;
	vector<string> refine;
	
	queries = refine;
	vector<int*> p;
	for (int i = 0; i < queries.size(); i++)
	{
		int* tmp = new int[queries[i].length() + 1]();
		p.push_back(tmp);
		preprocessing(queries[i], p[i]);
	}
	
	for (int i = 0; i < queries.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < words.size(); j++)
		{
			int q = 1, w = 1;
			string s = " " + words[j];
			string re_q = " " + queries[i];
			while (w < s.length())
			{
				if (q == 0 || s[w] == re_q.at(q))
				{
					q++;
					w++;
				}
				else
					q = p[i][q];
				if (q == re_q.length())
				{
					cnt++;
					q = p[i][q];
				}
			}
		}
		answer.push_back(cnt);
	}
	
	return answer;
}

int main()
{
	vector<string> words
		= { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries
		= { "fro??", "????o", "fr???", "fro???", "pro?" };
	vector<int> result = solution(words, queries);
	for (int i = 0; i < result.size(); i++)
	{
		printf("%d ", result[i]);
	}
	return 0;
}
#include <iostream>
#include <stack>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int loop, input;
	vector<int> v;
	stack<int> s,result;
	scanf("%d", &loop);
	while (loop--)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	
	for (int i = v.size() - 1; i >= 0; i--)
	{
		while (s.size() && s.top() <= v[i])
		{
			s.pop();
		}
		if (s.empty())
		{
			result.push(-1);
		}
		else
			result.push(s.top());
		s.push(v[i]);
	}

	while (result.size())
	{
		printf("%d ", result.top());
		result.pop();
	}

	return 0;
}
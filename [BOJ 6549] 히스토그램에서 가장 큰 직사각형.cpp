#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int number,input;
	do {
		scanf("%d", &number);
		vector<long long> v;
		for (int i = 0; i < number; i++)
		{
			long long tmp;
			scanf("%lld", &tmp);
			v.push_back(tmp);
		}
		
		stack<int> s;
		long long result = 0;
		for(int i=0; i<v.size(); i++)
		{
			while (s.size() && v[s.top()] > v[i])
			{
				long long h = v[s.top()];
				long long w = i;
				s.pop();
				if (s.size())
					w = i - s.top() - 1;
				result = max(result, h * w);
			}
			s.push(i);
		}
		
		while (s.size())
		{
			long long h = v[s.top()];
			long long w = number;
			s.pop();
			if (s.size())
				w = number - s.top() - 1;
			result = max(result, h * w);
		}
		if(number>0)
			printf("%lld\n", result);

	} while (number != 0);
	return 0;
}
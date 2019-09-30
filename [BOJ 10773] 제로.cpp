#include <iostream>
#include <stack>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int loop = 0;
	long long input = 0;
	scanf("%d", &loop);
	stack<long long> s;
	while (loop--)
	{
		scanf("%lld", &input);
		if (s.size() && !input)
			s.pop();
		else
			s.push(input);
	}
	long long result = 0;
	while(s.size())
	{
		result += s.top();
		s.pop();
	}
	printf("%lld\n", result);
	return 0;
}
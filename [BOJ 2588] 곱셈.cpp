#include <iostream>
#include <stack>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	stack<int> s;
	s.push(x * y);
	s.push(x * (y / 100));
	s.push(x * ((y / 10) % 10));
	s.push(x * (y % 10));

	while (s.size())
	{
		printf("%d\n", s.top());
		s.pop();
	}
		
	return 0;
}
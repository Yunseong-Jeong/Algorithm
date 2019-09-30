#include <iostream>
#include <queue>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input;
	scanf("%d", &input);
	queue<int> q;
	for (int i = 1; i <= input; i++)
	{
		q.push(i);
	}
	while (q.size() != 1)
	{
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	printf("%d\n", q.front());
	return 0;
}
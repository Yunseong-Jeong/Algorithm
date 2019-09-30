#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		printf("%d\n", x + y);
	}
	return 0;
}
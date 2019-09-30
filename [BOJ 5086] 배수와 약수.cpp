#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int x = -1, y = -1;
	while (true)
	{
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
			return 0;
		else if (y % x == 0)
			printf("factor\n");
		else if (x % y == 0)
			printf("multiple\n");
		else
			printf("neither\n");
	}
	return 0;
}
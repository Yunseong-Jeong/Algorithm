#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	if (x < y)
		printf("<\n");
	else if (x > y)
		printf(">\n");
	else
		printf("==\n");
	return 0;
}
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input,x,y;
	scanf("%d", &input);
	while (input--)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", x + y);
	}
	return 0;
}
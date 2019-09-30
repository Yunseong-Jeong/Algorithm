#include <iostream>

#pragma warning(disable:4996)

int main()
{
	int input,x, y;
	scanf("%d", &input);
	for(int i=1; i<=input; i++)
	{
		scanf("%d %d", &x, &y);
		printf("Case #%d: %d\n", i, x + y);
	}
	return 0;
}
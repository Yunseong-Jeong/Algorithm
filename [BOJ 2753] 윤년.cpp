#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int result,input;
	scanf("%d", &input);
	if (!(input % 4) && input % 100 || !(input % 400))
		result = 1;
	else
		result = 0;
	printf("%d\n", result);
	return 0;
}
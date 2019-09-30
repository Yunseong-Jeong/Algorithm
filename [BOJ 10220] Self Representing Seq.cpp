#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input_test;
	scanf("%d", &input_test);
	while (input_test--)
	{
		int input;
		scanf("%d", &input);
		if (input > 6 || input == 5)
			printf("1\n");
		else if (input == 4)
			printf("2\n");
		else
			printf("0\n");
	}
	return 0;
}
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input_x, input_y;
	while (true)
	{
		scanf("%d %d", &input_x, &input_y);
		if (!input_x && !input_y)
			break;
		printf("%d\n", input_x + input_y);
	}
	return 0;
}
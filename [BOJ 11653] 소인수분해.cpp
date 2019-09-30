#include <iostream>

#pragma warning(disable:4996)

using namespace	std;

int main()
{
	int input = 0, index = 2;
	scanf("%d", &input);
	
	while(input)
	{
		if (input == 1)
			break;
		if (input % index)
			index++;
		else
		{
			printf("%d\n", index);
			input /= index;
		}
	}
	return 0;
}

#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	long long input;
	scanf("%lld", &input);
	long long tmp = input;
	long long result = 1;
	if (input == 1)
	{
		printf("1\n");
		return 0;
	}
	while (input != 1)
	{
		for (long long i = 2; i <=input; i++)
		{
			long long cnt = 0;
			while (input%i == 0)
			{
				cnt++;
				input /= i;
			}
			if (cnt)
				result *= cnt+1;
			if (input == 1)
				break;
		}
	}
	printf("%lld\n", tmp - result+1);
	return 0;
}

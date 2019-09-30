#include <iostream>
#include <math.h>

#pragma	warning(disable:4996)

using namespace std;

int main()
{
	long long a, b, c;
	long long i = 0;
	scanf("%lld %lld %lld", &a, &b, &c);
	if (b >= c)
	{
		printf("-1\n");
		return 0;
	}
	i = a / (c - b) + 1;
	printf("%d\n", i);
	return 0;
}
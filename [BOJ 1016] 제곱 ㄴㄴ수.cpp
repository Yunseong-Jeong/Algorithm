#include <iostream>
#include <math.h>
#pragma warning(disable:4996)
bool dp[1000001] = { 0, };

int main()
{
	long long range_min, range_max;
	scanf("%lld %lld", &range_min, &range_max);
	int cnt = range_max - range_min + 1;
	for (long long i = 2; i*i <= range_max; i++)
	{
		long long divide = range_min / (i*i);
		if (divide * i*i < range_min)
			divide++;
		for (int j = 0; j < range_max - range_min + 1; j++)
		{
			if ((divide + j) * i* i - range_min >= range_max-range_min+1)
				break;
			else
			{
				if (dp[(divide + j) * i* i - range_min] != 1)
				{
					dp[(divide + j) * i* i - range_min] = 1;
					cnt--;
				}
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
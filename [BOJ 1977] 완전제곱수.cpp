#include <iostream>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

int dp[101] = { 0, };
int main()
{
	vector<int> v;
	int range_min, range_max,x,y;
	scanf("%d %d", &range_min, &range_max);
	for (int i = 1; i <= 100; i++)
	{
		dp[i] = i * i;
	}
	x = sqrt(range_min);
	y = sqrt(range_max);

	int result = 0, min = 0;
	for (int i = x; i <= y; i++)
	{
		if (dp[i] > range_max)
			break;
		else if (dp[i] >= range_min && dp[i] <= range_max)
		{
			if (!v.size())
				min = dp[i];
			v.push_back(dp[i]);
			result += dp[i];
		}
	}

	if (v.size())
		printf("%d\n%d", result, min);
	else
		printf("-1\n");
	return 0;
}
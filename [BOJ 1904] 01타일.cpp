#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input;
	scanf("%d", &input);
	int* dp = new int[input + 1];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= input; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= 15746;
	}

	printf("%d\n", dp[input]);
	return 0;
}
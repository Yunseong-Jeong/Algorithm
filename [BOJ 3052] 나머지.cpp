#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	bool dp[42] = { false, };
	int cnt=0;
	for (int i = 0; i < 10; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (dp[tmp % 42])
			continue;
		cnt++;
		dp[tmp % 42] = true;
	}
	printf("%d\n", cnt);
	return 0;
}
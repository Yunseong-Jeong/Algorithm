#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input,x,y;
	scanf("%d", &input);
	int* dp = new int[input];
	vector<pair<int, int>> v;
	while (input--)
	{
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[j].second < v[i].second && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	int result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		result = max(dp[i], result);
	}
	printf("%d\n", v.size() - result);
	return 0;
}
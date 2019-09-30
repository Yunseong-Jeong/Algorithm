#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input,tmp;
	scanf("%d", &input);
	vector<int> v;
	pair<int, int> dp[1001];
	for(int i=0; i<input; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	int inc = 0, dec = 0;
	for (int i = 0; i < input; i++)
	{
		dp[i].first = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i] && dp[i].first < dp[j].first + 1)
				dp[i].first = dp[j].first + 1;
		}
		
	}
	
	for (int i = input - 1; i >= 0; i--)
	{
		dp[i].second = 1;
		for (int j = input - 1; j >= i; j--)
		{
			if (v[j] < v[i] && dp[i].second < dp[j].second + 1)
				dp[i].second = dp[j].second + 1;
		}
	}
	
	int result = 0;
	for (int i = 0; i < input; i++)
	{
		result = max(result, (dp[i].first + dp[i].second - 1));
	}

	printf("%d\n", result);
	return 0;
}
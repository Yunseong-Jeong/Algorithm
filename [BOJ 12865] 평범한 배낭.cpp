#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int n, k, w , v;
	scanf("%d %d", &n, &k);
	int* dp = new int[k + 1]();
	vector<pair<int, int>> element;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &w, &v);
		element.push_back(make_pair(w, v));
	}

	sort(element.begin(), element.end());
	
	for (int i = 0; i<n; i++)
	{
		for (int j = k; j >= 0; j--)
		{
			if(element[i].first <= j)
				dp[j] = max(dp[j], dp[j-element[i].first]+element[i].second);
		}
	}
	
	printf("%d\n", dp[k]);
	return 0;
}
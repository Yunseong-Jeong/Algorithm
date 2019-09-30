#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input;
	scanf("%d", &input);
	int *arr = new int[input];
	vector<pair<int,int>> v;
	for (int i = 0; i < input; i++)
	{
		scanf("%d", &arr[i]);
		v.push_back(make_pair(arr[i],i));
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (arr[i] == v[j].first && i == v[j].second)
				printf("%d ", j);
		}
	}
	printf("\n");
	return 0;
}
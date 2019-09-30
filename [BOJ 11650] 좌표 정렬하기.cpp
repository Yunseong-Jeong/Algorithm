#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
	if (x.first != y.first)
		return x.first < y.first;
	else
		return x.second < y.second;
}


int main()
{
	int input_n, x, y;
	scanf("%d", &input_n);
	vector<pair<int, int>> v;
	while (input_n--)
	{
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}
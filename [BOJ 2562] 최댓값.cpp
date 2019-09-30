#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

bool cmp(pair<int, int>& i, pair<int, int>& j)
{
	return i.first > j.first;
}


int main()
{
	int input;
	vector<pair<int, int>> v;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &input);
		v.push_back(make_pair(input, i));
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v[0].first);
	printf("%d\n", v[0].second +1);
	return 0;
}
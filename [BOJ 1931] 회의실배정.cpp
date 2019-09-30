#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool cmp(const pair<int, int>& x, const pair<int, int>& y)
{
	if (x.second == y.second)
		return x.first < y.first;
	else
		return x.second < y.second;
}

int main()
{
	int start, end, input;
	scanf("%d", &input);
	vector<pair<int, int>> v;
	while (input--)
	{
		scanf("%d %d", &start, &end);
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), cmp);
	int time = 0, cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int meeting_Start = v[i].first;
		int meeting_End = v[i].second;
		if (meeting_Start >= time && meeting_End >= time)
		{
			time = meeting_End;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
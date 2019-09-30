#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool cmp(const pair<int, int>& x, const pair<int, int>& y)
{
	return x.second < y.second;
}

int main()
{
	int input_x, input_y;
	vector<pair<int, int>>x, y;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &input_x, &input_y);
		bool check_x = true, check_y = true;
		for (int j = 0; j < x.size(); j++)
		{
			if (x[j].first == input_x)
			{
				x[j].second++;
				check_x = false;
				break;
			}
		}

		if (check_x)
			x.push_back(make_pair(input_x, 1));

		for (int j = 0; j < y.size(); j++)
		{
			if (y[j].first == input_y)
			{
				y[j].second++;
				check_y = false;
				break;
			}
		}

		if (check_y)
			y.push_back(make_pair(input_y, 1));
	}
	
	sort(x.begin(), x.end(), cmp);
	sort(y.begin(), y.end(), cmp);
	printf("%d %d\n", x[0].first, y[0].first);
	return 0;
}
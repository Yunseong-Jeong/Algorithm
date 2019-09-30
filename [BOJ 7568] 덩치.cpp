#include <iostream>
#include <vector>


#pragma warning(disable:4996)

#define MIN(x,y) x>y ? y : x
#define MAX(x,y) x>y ? x : y

using namespace std;

int main()
{
	vector<pair<int,int>> v;
	int count, x, y;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 1;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				cnt++;
		}
		printf("%d ", cnt);
	}
	printf("\n");
	return 0;
}
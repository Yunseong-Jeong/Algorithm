#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	vector<int> v;
	int input_cnt,tmp;
	scanf("%d", &input_cnt);
	for (int i = 0; i < input_cnt; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	printf("%d %d\n", v[0], v[v.size() - 1]);
	return 0;
}
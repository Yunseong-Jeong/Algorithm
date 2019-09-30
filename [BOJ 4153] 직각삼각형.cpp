#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int x, y, z;
	while (true)
	{
		scanf("%d %d %d", &x, &y, &z);
		if (!x && !y && !z)
			break;
		vector<int> v;
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
		sort(v.begin(), v.end());
		if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}
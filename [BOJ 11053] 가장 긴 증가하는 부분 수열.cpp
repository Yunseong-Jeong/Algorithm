#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input, x;
	vector<int> v;
	v.push_back(-1);
	scanf("%d", &input);
	int result = 0;
	for (int i=0; i<input; i++)
	{
		scanf("%d", &x);
		if (v.back() < x)
		{
			v.push_back(x);
			result++;
		}
		else
		{
			auto it = lower_bound(v.begin(), v.end(), x);
			*it = x;
		}
	}
	
	printf("%d\n", result);
	return 0;
}
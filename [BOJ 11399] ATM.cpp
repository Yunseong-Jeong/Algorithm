#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int n, p;
	vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p);
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	int result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		result += v[i] * (v.size()- i);
	}
	printf("%d\n", result);
	return 0;
}
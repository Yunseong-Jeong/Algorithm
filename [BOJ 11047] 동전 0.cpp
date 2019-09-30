#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int n, k, input;
	scanf("%d %d", &n, &k);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	sort(v.begin(), v.end(), greater<int>());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cnt += (k / v[i]);
		k %= v[i];
	}
	printf("%d\n", cnt);
	return 0;
}
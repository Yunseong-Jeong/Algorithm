#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input,n;
	scanf("%d\n", &n);
	vector<int> v;
	while (n--)
	{
		scanf("%d", &input);
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	printf("%d\n", v[0] * v[v.size() - 1]);
	return 0;
}
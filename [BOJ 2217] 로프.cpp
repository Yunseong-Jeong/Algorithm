#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int n, w, result = -1;
	vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &w);
		v.push_back(w);
		if (result < w)
			result = w;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int tmp = v[i] * (v.size() - i);
		result = max(result, tmp);
	}
	printf("%d\n", result);
	return 0;
}
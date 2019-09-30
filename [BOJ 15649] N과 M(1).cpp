#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	void backtrack(vector<int> v, bool* check, int& cnt, int n, int m);
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> v;
	bool* check = new bool[n]();
	int cnt = 0;
	backtrack(v, check, cnt, n, m);
	return 0;
}

void backtrack(vector<int> v,bool* check, int& cnt,int n, int m)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			v.push_back(i + 1);
			cnt++;
			backtrack(v, check, cnt, n, m);
			cnt--;
			check[i] = false;
			v.pop_back();
		}
	}
	return;
}
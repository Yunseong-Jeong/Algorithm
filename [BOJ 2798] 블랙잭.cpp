#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input_n, input_m, tmp, key = 3;
	stack<int> s;
	s.push(0);
	vector<int> v,index;
	scanf("%d %d", &input_n, &input_m);
	for (int i = 0; i < input_n; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	
	for (int i = 0; i < key; i++)
	{
		index.push_back(1);
	}

	for (int i = 0; i < v.size() - key; i++)
	{
		index.push_back(0);
	}

	sort(index.begin(), index.end());
	do
	{
		int tmp = 0;
		for (int i = 0; i < index.size(); i++)
		{
			if (index[i])
				tmp += v[i];
		}
		if (s.top() < tmp && tmp <= input_m)
			s.push(tmp);
	} while (next_permutation(index.begin(), index.end()));
	int result = s.top();
	printf("%d\n", result);
	return 0;
}
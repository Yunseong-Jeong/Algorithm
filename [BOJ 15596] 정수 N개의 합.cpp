#include <iostream>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

long sum(vector<int> &a)
{
	long result = 0;
	for (int i = 0; i < a.size(); i++)
	{
		result += a[i];
	}
	return result;
}
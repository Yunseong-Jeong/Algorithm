#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

bool cmp(const pair<int, string>& x, const pair<int, string>& y)
{
	return x.first < y.first;
}


int main()
{
	int input, x;
	string s;
	scanf("%d", &input);
	vector < pair<int, string>> v;
	while (input--)
	{
		cin >> x >> s;
		v.push_back(make_pair(x, s));
	}
	stable_sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i].first<<" " <<v[i].second<<"\n";
	}
	return 0;
}
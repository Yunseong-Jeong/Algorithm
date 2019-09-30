#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>

#pragma warning(disable:4996)

bool button[10];

using namespace std;



void check(int size, int depth, int *selected, vector<int> v, vector<int> *tmp)
{
	int i;
	if (size == depth)
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += selected[i] * pow(10, size - 1 - i);
		}
		tmp->push_back(sum);
		return;
	}
	for (i = 0; i < v.size(); i++)
	{
		selected[depth] = v[i];
		check(size, depth + 1, selected, v, tmp);
	}
}


int main()
{
	int object = 0;
	int num = 0;
	int here = 100;
	int input;
	int ans = 0;
	int upper_start;
	int lower_start;
	vector<int> v;
	vector<int> tmp;
	vector<int>left;
	vector<int>right;
	for (int i = 0; i < 10; i++)
	{
		button[i] = true;
	}
	scanf("%d", &object);
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &input);
		button[input] = false;
	}

	string convert = to_string(object);
	int size = 0;
	size = convert.length();

	for (int i = 0; i < 10; i++)
	{
		if (button[i])
			v.push_back(i);
	}
	if (object != here)
	{

		int *select = new int[size];
		check(size, 0, select, v, &tmp);

		if (size >= 1 && v.size())
		{
			int c = 0;
			for (int i = 0; i < size - 1; i++)
			{
				c *= 10;
				c += v[v.size() - 1];
			}
			if (c != 0)
				tmp.push_back(c);
			c = 0;
			for (int i = 0; i < size + 1; i++)
			{
				c *= 10;
				for (int j = 0; j < v.size(); j++)
				{
					if (i == 0 && v[j] == 0)
						continue;
					else
					{
						c += v[j];
						break;
					}
				}
			}
			if (c != 0)
				tmp.push_back(c);
		}

		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] <= object)
				left.push_back(tmp[i]);
			else
				right.push_back(tmp[i]);
		}


		sort(left.begin(), left.end(), greater<int>());
		sort(right.begin(), right.end());
		int c_l = 5000001;
		int c_r = 5000001;
		if (left.size())
			c_l = left[0];
		if (right.size())
			c_r = right[0];


		if (abs(c_l - object) <= abs(c_r - object))
		{
			if (abs(here - object) - abs(c_l - object) > size)
			{
				here = c_l;
				convert = to_string(c_l);
				ans += convert.length();
			}

		}
		else
		{
			if (abs(here - object) - abs(c_r - object) > size)
			{
				here = c_r;
				convert = to_string(c_r);
				ans += convert.length();
			}
		}
	}


	while (object != here)
	{
		if (here == object)
			break;
		else if (here < object)
			here++;
		else
			here--;

		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

struct Point {
	int x, y;
	Point()
	{
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool operator < (const Point& p) const 
	{
		if (y == p.y)
		{
			return x < p.x;
		}
		else
			return y < p.y;
	}
};

bool cmp_x(Point x, Point y)
{
	return x.x < y.x;
}

bool cmp_y(Point x, Point y)
{
	return x.y < y.y;
}


int main()
{
	int distance(Point x, Point y);
	int n, x, y;
	scanf("%d", &n);
	vector<Point> v;
	while (n--)
	{
		scanf("%d %d", &x, &y);
		v.push_back(Point(x,y));
	}
	sort(v.begin(), v.end(), cmp_x);

	set<Point> candidate = { v[0], v[1] };
	int result = distance(v[0], v[1]);
	int start = 0;
	for (int i = 2; i < v.size(); i++)
	{
		Point now = v[i];
		while (start < i)
		{
			auto p = v[start];
			int x = now.x - p.x;
			if (x * x > result)
			{
				candidate.erase(p);
				start++;
			}
			else
				break;
		}
		int d = (int)sqrt((double)result) + 1;
		auto lower_point = Point(-100000, now.y - d);
		auto upper_point = Point(100000, now.y + d);
		auto lower = candidate.lower_bound(lower_point);
		auto upper = candidate.upper_bound(upper_point);
		for (auto index = lower; index != upper; index++)
		{
			int d = distance(now, *index);
			if (d < result)
				result = d;
		}
		candidate.insert(now);
	}
	printf("%d\n", result);
	return 0;
}

int distance(Point a, Point b)
{
	int result = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return result;
}
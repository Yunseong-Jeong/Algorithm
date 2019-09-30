#include <iostream>
#include <vector>
#include <utility>

#pragma warning(disable:4996)

using namespace std;

vector<pair<int, int>> v;
int cnt = 0;

void move(int from, int to)
{
	v.push_back(make_pair(from, to));
	cnt += 1;
}

void hanoi(int n, int from, int by, int to )
{
	if (n == 1)
		move(from, to);
	else
	{
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}


int main()
{
	int input = 0;
	
	scanf("%d", &input);
	hanoi(input, 1, 2, 3);
	printf("%d\n", cnt);
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}
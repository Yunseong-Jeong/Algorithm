#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int calc(int x, int mod)
{
	int current = x;
	int cnt = 0;
	while (current > 0)
	{
		current /= mod;
		cnt += current;
	}
	return cnt;
}

int main()
{
	int n, m;
	int two_cnt = 0, five_cnt = 0;
	scanf("%d %d", &n, &m);
	two_cnt = calc(n, 2) - calc(m, 2) - calc(n - m, 2);
	five_cnt = calc(n, 5) - calc(m, 5) - calc(n - m, 5);
	int result = min(two_cnt, five_cnt);
	printf("%d\n", result);
	return 0;
}
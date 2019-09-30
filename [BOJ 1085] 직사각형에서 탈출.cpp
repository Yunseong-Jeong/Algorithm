#include <iostream>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

#define MIN(x,y) x>y ? y: x

int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int tmp1 = MIN(x, w - x);
	int tmp2 = MIN(y, h - y);
	int result = MIN(tmp1, tmp2);
	printf("%d\n", result);
	return 0;
}

#include <iostream>
#include <vector>

#pragma warning (disable:4996)

using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int days = (c - a) / (a - b) + 1;
	if ((c - a) % (a - b))
		days++;
	printf("%d\n", days);
	return 0;
}
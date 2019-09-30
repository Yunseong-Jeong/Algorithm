#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int h, m;
	scanf("%d %d", &h, &m);
	m -= 45;
	if (m < 0)
	{
		m += 60;
		h--;
		if (h < 0)
			h = 23;
	}
	printf("%d %d\n", h, m);
	return 0;
}
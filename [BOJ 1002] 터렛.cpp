#include <iostream>
#include <math.h>
#pragma warning(disable:4996)

#define MAX(x,y) x>y ? x: y
#define MIN(x,y) x>y ? y: x
using namespace std;

int main()
{
	int input_t;
	scanf("%d", &input_t);
	while (input_t--)
	{
		int x1, y1, r1, x2, y2, r2;
		
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		
		int min_r = MIN(r1, r2);
		int max_r = MAX(r1, r2);

		if (x1 == x2 && y1 == y2 && r1 == r2) //일치
			printf("-1\n");
		else if (distance * distance == (r1 + r2) * (r1 + r2)) // 외접
			printf("1\n");
		else if ((distance + min_r) * (distance + min_r) == max_r * max_r)// 내접
			printf("1\n");
		else if (distance * distance > (r1 + r2) * (r1 + r2)) // 떨어져 있고, 만나지 않는경우
			printf("0\n");
		else if ((distance + min_r) * (distance + min_r) < max_r * max_r)
			printf("0\n");
		else
			printf("2\n");
	
	}
	return 0;
}
#include <iostream>
#pragma warning(disable:4996)

using namespace std;
long long N, r, c;
long long Z(long long pos_x, long long pos_y, long long size)
{
	if (size != 2)
	{
		if (pos_x >= size / 2 && pos_y >= size / 2)
			return (size * size / 4 * 3) + Z(pos_x - size / 2, pos_y - size / 2, size / 2);
		else if (pos_x >= size / 2)
			return (size * size / 2) + Z(pos_x - size / 2, pos_y, size / 2);
		else if (pos_y >= size / 2)
			return (size * size / 4) + Z(pos_x, pos_y - size / 2, size / 2);
		else
			return Z(pos_x, pos_y, size / 2);
	}
	else
	{
		long long cnt = 0;
		for (int i = 0; i < 2 ; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cnt++;
				if (i == pos_x  && j == pos_y)
					return cnt;
			}
		}
	}
}

int main()
{
	scanf("%lld %lld %lld", &N, &r, &c);
	long long size = 1;
	for (int i = 0; i < N; i++)
	{
		size *= 2;
	}
	printf("%lld\n", Z(r, c, size)-1);
	return 0;
}
#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

#define DIVIDE 1000000007

class Matrix
{
private:
	unsigned long long x;
	unsigned long long y;
	unsigned long long z;
	unsigned long long w;
public:
	Matrix()
	{
		x = 1;
		y = 1;
		z = 1;
		w = 0;
	}
	Matrix(int i)
	{
		x = 1;
		y = 0;
		z = 0;
		w = 1;
	}
	void multi(Matrix m)
	{
		unsigned long long tmp_x = x;
		unsigned long long tmp_y = y;
		unsigned long long tmp_z = z;
		unsigned long long tmp_w = w;
		x = tmp_x * m.x + tmp_y * m.z;
		y = tmp_x * m.y + tmp_y * m.w;
		z = tmp_z * m.x + tmp_w * m.z;
		w = tmp_z * m.y + tmp_w * m.w;
		x %= DIVIDE;
		y %= DIVIDE;
		z %= DIVIDE;
		w %= DIVIDE;
	}
	long long getY() {
		return y;
	}
};


unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	unsigned long long x, y;
	scanf("%lld %lld", &x, &y);
	if (x > y)
	{
		unsigned long long tmp = x;
		x = y;
		y = tmp;
	}
	unsigned long long z = gcd(x, y);
	
	Matrix F = Matrix();
	Matrix E = Matrix(1);
	if (z == 0)
		printf("0\n");
	else if (z == 1)
		printf("1\n");
	else
	{
		while (z > 0)
		{
			if (z % 2)
				E.multi(F);
			F.multi(F);
			z /= 2;
		}
		printf("%d\n", E.getY()%DIVIDE);
	}
	return 0;
}
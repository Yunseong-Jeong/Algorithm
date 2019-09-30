#include <iostream>

#pragma warning(disable:4996)

int main()
{
	long long multi(long long a, long long b, long long c);
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	long long result = multi(a, b, c);
	printf("%lld\n", result);
	return 0;
}

long long multi(long long a, long long b, long long c)
{
	if (b == 1)
		return a % c;
	if (b % 2)
		return ((multi(a, b / 2 + 1, c) % c) * (multi(a, b / 2, c) % c)) % c;
	else
		return ((multi(a, b / 2, c) % c) * (multi(a, b / 2, c) % c)) % c;
}
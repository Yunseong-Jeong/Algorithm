#include <iostream>
#include <map>
#include <string>

#pragma warning(disable:4996)

using namespace std;

string arr[100001];
map<string, int> v;
int main()
{
	char str[21];
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		string input = str;
		v.insert(pair<string, int>(input,i));
		arr[i] = input;
	}

	for (int j = 0; j < m; j++)
	{
		scanf("%s", str);
		string input = str;
		if (input.at(0) >= '0' && input.at(0) <= '9')
			cout<< arr[stoi(input)]<<"\n";
		else
			printf("%d\n", v[input]);
	}
	return 0;
}


#include <iostream>
#include <string>

#pragma warning(disable:4996)

#define MIN(x,y) x>y? y : x

using namespace std;

int count(char **current, string* map, int x, int y)
{
	int result = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (current[i+x][j+y] != map[i].at(j))
				result++;
		}
	}
	return result;
}


int main()
{
	int n, m;
	string white_map[8] = {
		{ "WBWBWBWB" }, { "BWBWBWBW" }, { "WBWBWBWB" }, { "BWBWBWBW" },
		{ "WBWBWBWB" }, { "BWBWBWBW" }, { "WBWBWBWB" }, { "BWBWBWBW" }
	};
	string black_map[8] = {
		{"BWBWBWBW"} , {"WBWBWBWB"} , {"BWBWBWBW"} , {"WBWBWBWB"} ,
		{"BWBWBWBW"} , {"WBWBWBWB"} , {"BWBWBWBW"} , {"WBWBWBWB"}
	};
	scanf("%d %d", &n, &m);
	char** map = new char *[n];
	for (int i = 0; i < n; i++)
	{
		map[i] = new char[m];
	}
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s.at(j);
		}
	}

	int result = 2501;

	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			int tmp;
			tmp = count(map, white_map, i, j);
			result = MIN(result, tmp);
			tmp = count(map, black_map, i, j);
			result=MIN(result, tmp);
		}
	}
	printf("%d\n", result);
	
	return 0;
}
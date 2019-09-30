#include <iostream>

#pragma warning(disable:4996)

using namespace std;


int main()
{
	pair<int, int> calc(int** map, int x_start_index, int x_end_index, int y_start_index, int y_end_index, pair<int, int> & result);
	int input;
	scanf("%d", &input);
	pair<int, int> result = make_pair(0,0);
	int** map = new int* [input];
	for (int i = 0; i < input; i++)
	{
		map[i] = new int[input]();
	}
	int tmp;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			scanf("%d", &tmp);
			map[i][j] = tmp;
		}
	}

	result = calc(map, 0, input, 0, input, result);
	printf("%d\n%d\n", result.first, result.second);
	return 0;
}

pair<int, int> calc(int **map,int x_start_index, int x_end_index, int y_start_index, int y_end_index, pair<int, int>& result)
{	
	int prev = -1;
	bool ischeck = true;
	for (int i = x_start_index; i < x_end_index; i++)
	{
		for (int j = y_start_index; j < y_end_index; j++)
		{
			if (prev == -1)
				prev = map[i][j];
			else if (prev != map[i][j])
			{
				ischeck = false;
				break;
			}
		}
		if (!ischeck)
			break;
	}
	if (ischeck)
	{
		if (prev)
			result.second += 1;
		else
			result.first += 1;
	}
	else
	{
		int delta_x = (x_end_index - x_start_index) / 2;
		int delta_y = (y_end_index - y_start_index) / 2;
		calc(map, x_start_index, x_start_index + delta_x, y_start_index, y_start_index + delta_y,result);
		calc(map, x_start_index + delta_x, x_end_index, y_start_index, y_start_index + delta_y, result);
		calc(map, x_start_index, x_start_index + delta_x, y_start_index + delta_y, y_end_index, result);
		calc(map, x_start_index + delta_x, x_end_index, y_start_index + delta_y, y_end_index, result);		
	}
	return result;
}
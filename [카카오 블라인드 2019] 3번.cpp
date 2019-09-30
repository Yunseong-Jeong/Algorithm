#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	bool answer = true;
	int min_lock_x = 21 , min_lock_y=21;
	int max_lock_x = -1, max_lock_y = -1;
	for (int i = 0; i < lock.size(); i++)
	{
		for (int j = 0; j < lock.size(); j++)
		{
			if (!lock[i][j])
			{
				min_lock_x = min(min_lock_x, i);
				min_lock_y = min(min_lock_y, j);
				max_lock_x = max(max_lock_x, i);
				max_lock_y = max(max_lock_y, j);
			}
		}
	}

	int delta_x = max_lock_x - min_lock_x;
	int delta_y = max_lock_y - min_lock_y;
	int** check = new int* [delta_x+1];
	for (int i = 0; i <= delta_x; i++)
	{
		check[i] = new int[delta_y+1]();
	}
	for (int i = min_lock_x; i <= max_lock_x; i++)
	{
		for (int j = min_lock_y; j <= max_lock_y; j++)
		{
			check[i-min_lock_x][j-min_lock_y] = (lock[i][j]);
		}
	}
	
	for (int n = 0; n < 4; n++)
	{
		int** rotate = new int* [delta_y + 1];
		for (int i = 0; i <= delta_y; i++)
		{
			rotate[i] = new int[delta_x + 1]();
		}
		for (int i = 0; i < delta_x+1; i++)
		{
			for (int j = 0; j < delta_y+1; j++)
			{
				//if (rotate[j].size() < check.size() - 1 - i)
				//	rotate[j].push_back(check[i][j]);
				//else
					rotate[j][delta_x - i] = check[i][j];
			}
		}
		check = rotate;
		int tmp = delta_x;
		delta_x = delta_y;
		delta_y = tmp;
		
		for (int dx = 0; dx <=key.size()- (delta_x+1); dx++)
		{
			for (int dy = 0; dy <=key[dx].size()- (delta_y+1); dy++)
			{
				answer = true;
				for (int i = 0; i < delta_x+1; i++)
				{
					for (int j = 0; j < delta_y+1; j++)
					{
						if (key[dx + i][dy + j] + check[i][j] < 1)
						{
							answer = false;
							break;
						}
					}
				}
				if (answer)
				{
					answer = true;
					return answer;
				}
			}
		}
	}
	return false;
}


int main()
{
	vector<vector<int>> key = 
		//{ {0,0,0}, {0,0,1}, {0,0,0} };
		{ {0,0,0}, {0,0,0}, {0,1,1} };
	vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	//{ {1, 1, 1}, {0, 1, 0}, {1, 1, 1} };
	bool check = solution(key, lock);
	if (check)
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
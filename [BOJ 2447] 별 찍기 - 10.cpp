#include <iostream>
#pragma warning(disable:4996)

char star[6561][6561];

void makestar(int pos_x, int pos_y, int size)
{
	if (size > 3)
	{
		makestar(pos_x, pos_y, size / 3);
		makestar(pos_x + size/ 3, pos_y, size / 3);
		makestar(pos_x + size / 3 * 2, pos_y, size / 3);
		makestar(pos_x, pos_y + size / 3, size / 3);
		makestar(pos_x + size / 3 * 2, pos_y + size / 3, size / 3);
		makestar(pos_x, pos_y + size / 3 * 2, size / 3);
		makestar(pos_x + size / 3, pos_y + size / 3 * 2, size / 3);
		makestar(pos_x + size / 3 * 2, pos_y + size / 3 * 2, size / 3);
	}
	else
	{
		for (int i = pos_x; i < pos_x + 3; i++)
		{
			for (int j = pos_y; j < pos_y + 3; j++)
			{
				if (i == pos_x + 1 && j == pos_y + 1)
					star[i][j] = ' ';
				else
					star[i][j] = '*';
			}
		}
	}
}

int main()
{
	int input;
	scanf("%d", &input);
	int size = 1;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			star[i][j] = ' ';
		}
	}

	makestar(0, 0, input);

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
	return 0;
}
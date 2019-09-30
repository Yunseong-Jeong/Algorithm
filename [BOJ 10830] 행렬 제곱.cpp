#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	vector<vector<int>> calc(vector<vector<int>> matrix, long long loop_cnt, int n);
	int n, input;
	long long loop_cnt;
	scanf("%d %lld", &n, &loop_cnt);
	vector<vector<int>> matrix;
	for (int i = 0; i < n; i++)
	{
		vector<int> element;
		matrix.push_back(element);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &input);
			matrix[i].push_back(input);
		}
	}
	vector<vector<int>> result = calc(matrix, loop_cnt, n);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			printf("%d ", result[i][j] % 1000);
		}
		printf("\n");
	}
	return 0;
}

vector<vector<int>> inner(vector<vector<int>> a, vector<vector<int>> b, int n)
{
	vector<vector<int>> v;
	for (int i = 0; i < n; i++)
	{
		vector<int> element;
		v.push_back(element);
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += (a[i][k]%1000) * (b[k][j] % 1000) % 1000;
			}
			sum %= 1000;
			v[i].push_back(sum);
		}
	}
	return v;
}

vector<vector<int>> calc(vector<vector<int>> matrix, long long loop_cnt, int n)
{
	vector<vector<int>> current;
	if (loop_cnt == 1)
	{
		return matrix;
	}
	current = calc(matrix, loop_cnt / 2, n);
	current = inner(current, current, n);
	if (loop_cnt % 2)
		current = inner(current, matrix, n);
	return current;
}


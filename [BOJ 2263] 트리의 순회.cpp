#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

void convert(vector<int> &in , vector<int> &post, int in_start_index,int in_end_index, int post_start_index, int post_end_index , queue<int> &pre)
{
	if (in_start_index > in_end_index || post_start_index > post_end_index)
		return;
	pre.push(post[post_end_index]);
	int pivot;
	for (int i = in_start_index; i <= in_end_index; i++)
	{
		if(in[i] == post[post_end_index])
		{
			pivot = i;
			break;
		}
	}
	int size = pivot - in_start_index;
	convert(in, post, in_start_index, pivot - 1, post_start_index, post_start_index + size - 1, pre);
	convert(in, post, pivot + 1, in_end_index, post_start_index + size, post_end_index - 1, pre);
}


int main()
{
	int input;
	scanf("%d", &input);
	vector<int> inorder;
	vector<int> postorder;
	queue<int> preorder;
	int tmp;
	for (int i = 0; i < input; i++)
	{
		scanf("%d", &tmp);
		inorder.push_back(tmp);
	}

	for (int i = 0; i < input; i++)
	{
		scanf("%d", &tmp);
		postorder.push_back(tmp);
	}

	convert(inorder, postorder, 0, input - 1, 0, input - 1, preorder);

	while (preorder.size())
	{
		printf("%d ", preorder.front());
		preorder.pop();
	}
	printf("\n");
	
	return 0;
}
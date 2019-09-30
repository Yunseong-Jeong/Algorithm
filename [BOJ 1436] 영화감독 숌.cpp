#include <iostream>
#include <string>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int input;
	scanf("%d", &input);
	int start = 665;
	int cnt = 0;
	while (start++)
	{
		string s = to_string(start);
		int six_cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s.at(i) == '6')
				six_cnt++;
			else
				six_cnt = 0;
			if (six_cnt == 3)
				cnt++;
		}

		if (cnt == input)
		{
			printf("%d\n", start);
			return 0;
		}
	}
}
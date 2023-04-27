#include <stdio.h>

int main()
	{
	int array[] = {12, 13, 14, 15, 16, 17, 18, 19, 207};
	int a [2][2] = {1, 1, 1, 4};
	int b [2][2] = {1, 2, 4, 1};
	int c [2][2] = {};
	for (int i = 0; i < 9; i ++)
	{
		if (i + 1 % 3 == 0)
		{
			printf("%d\n", array[i]);
		}
		else
		{
			printf("%d ", array[i]);
		}
	}
		printf("\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	printf("%d %d\n", c[0][1], c[0][1]);
	printf("%d %d\n", c[1][0], c[1][1]);
	return 0;
}

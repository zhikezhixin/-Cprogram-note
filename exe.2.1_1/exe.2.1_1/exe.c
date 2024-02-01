#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3) == 1 &&
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(c == 5) + (d == 3) == 1 &&
							(e == 4) + (a == 1) == 1)
						{
							if (a * b * c * d * e == 120)
							{
								printf("a=%d b=%d c=%d d=%d e=%d",a,b,c,d,e);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}


int main()
{
	char a = 0;
	char b = 0;
	char c = 0;
	char d = 0;
	char killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("killer=%c\n",killer);
		}
	}

	return 0;
}

#define row 20
int main()
{
	int arr[row][row] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (j == 0||i == j)
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row - 1 - i; j++)
		{
			printf("   ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%5d ",*(*(arr+i)+j));
		}
		printf("\n");
	}

	return 0;
}






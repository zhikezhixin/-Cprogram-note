#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>







int main()
{
	int arr[2][3] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			scanf("%d", (*(arr + i) + j));
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d", *(*(arr + i) + j));
		}
	}
	return 0;
}
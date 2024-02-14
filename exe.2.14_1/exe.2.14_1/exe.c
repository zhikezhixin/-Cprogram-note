#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//输出一个矩阵的转置矩阵
int main()
{
	int A[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int i = 0;
	int j = 0;
	printf("矩阵A为:\n");
	for (i = 0; i < 3; i++)//外循环：行
	{
		for (j = 0; j < 4; j++)//内循环：列
		{
			printf("%d ",*(*(A + i) + j));//行作内循环固定，将列不断变化
		}
		printf("\n");

	}
	printf("\n");
	printf("A的逆矩阵为：\n");
	for (j = 0; j < 4; j++)//外循环：列
	{
		for (i = 0; i < 3; i++)//内循环：行
		{
			printf("%d ", *(*(A + i) + j));//列做外循环固定，将行不断变化
		}
		printf("\n");

	}
	return 0;
}

//上三角矩阵的判定
#define N 3

int is_up_angle1(int (*arr)[N])
{
	int tem = 1;
	for (int i = 0; i < N && tem != 0; i++)
	{
		for (int j = 0; j < i; j++)//下三角元素特征：列标小于行标
		{
			if (*(*(arr + i) + j) != 0)
			{
				tem = 0;
				return tem;
				
			}
		}
	}
	return tem;
}

int is_up_angle2(int (*arr)[N])
{
	int tem = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			tem += *(*(arr + i) + j);
		}
	}
	return tem;
}

int main()
{
	int arr[N][N] = { 0 };
	int i = 0;
	int j = 0;
	int tem1 = 1;
	int tem2 = 1;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d",&arr[i][j]);// scanf（）用下标输入时，要取地址
		}
	}
	//法一：判断下三角元素是否都为0
	tem1 = is_up_angle1(arr);
	//法二：判断下三角元素之和是否为零
	tem2 = is_up_angle2(arr);
	if (tem1 == 1)
	{
		printf("是上三角矩阵\n");
	}
	else
	{
		printf("不是上三角矩阵\n");
	}
	if (tem2 == 0)
	{
		printf("是上三角矩阵\n");
	}
	else
	{
		printf("不是上三角矩阵\n");
	}
	return 0;
}

//判断数列的有序性
int main()
{
	int n = 0;
	int arr[50] = { 0 };
	int i = 0;
	int tem1 = 0;
	int tem2 = 0;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
		if (i > 0)
		{
			if (arr[i] > arr[i - 1])
			{
				tem1 = 1;
			}
			else if (arr[i] < arr[i - 1])
			{
				tem2 = 1;
			}
			else
			{
				;
			}
		}
	}
	if (tem1 + tem2 <= 1)
	{
		if (tem1 == 1)
		{
			printf("升序\n");
		}
		else
		{
			printf("降序\n");
		}
	}
	else
	{
		printf("无序\n");
	}

	return 0;
}
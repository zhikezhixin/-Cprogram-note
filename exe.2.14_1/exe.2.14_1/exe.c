#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//���һ�������ת�þ���
int main()
{
	int A[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int i = 0;
	int j = 0;
	printf("����AΪ:\n");
	for (i = 0; i < 3; i++)//��ѭ������
	{
		for (j = 0; j < 4; j++)//��ѭ������
		{
			printf("%d ",*(*(A + i) + j));//������ѭ���̶������в��ϱ仯
		}
		printf("\n");

	}
	printf("\n");
	printf("A�������Ϊ��\n");
	for (j = 0; j < 4; j++)//��ѭ������
	{
		for (i = 0; i < 3; i++)//��ѭ������
		{
			printf("%d ", *(*(A + i) + j));//������ѭ���̶������в��ϱ仯
		}
		printf("\n");

	}
	return 0;
}

//�����Ǿ�����ж�
#define N 3

int is_up_angle1(int (*arr)[N])
{
	int tem = 1;
	for (int i = 0; i < N && tem != 0; i++)
	{
		for (int j = 0; j < i; j++)//������Ԫ���������б�С���б�
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
			scanf("%d",&arr[i][j]);// scanf�������±�����ʱ��Ҫȡ��ַ
		}
	}
	//��һ���ж�������Ԫ���Ƿ�Ϊ0
	tem1 = is_up_angle1(arr);
	//�������ж�������Ԫ��֮���Ƿ�Ϊ��
	tem2 = is_up_angle2(arr);
	if (tem1 == 1)
	{
		printf("�������Ǿ���\n");
	}
	else
	{
		printf("���������Ǿ���\n");
	}
	if (tem2 == 0)
	{
		printf("�������Ǿ���\n");
	}
	else
	{
		printf("���������Ǿ���\n");
	}
	return 0;
}

//�ж����е�������
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
			printf("����\n");
		}
		else
		{
			printf("����\n");
		}
	}
	else
	{
		printf("����\n");
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�����ַ���
int main()
{
	int k = 0;
	int i = 0;
	int j = 0;
	char arr[] = "ABCDE";
	int len = strlen(arr);
	scanf("%d",&k);
	k %= len;
	for (i = 0; i < k; i++)
	{
		char tem = arr[0];
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[len - 1] = tem;
	}
	printf("%s\n",arr);

	return 0;
}


#include <assert.h>
void reverse(char* p1, char* p2)
{
	assert(p1 && p2);
	while (p1 < p2)
	{
		char tem = *p1;
		*p1 = *p2;
		*p2 = tem;
		p1++;
		p2--;
	}
}

void left_rotate(char* parr, int len,int k)
{
	k %= len;
	reverse(parr,parr +k  -1);
	reverse(parr + k,parr + len -1);
	reverse(parr,parr + len -1);

}

int main()
{
	char arr[] = "ABCDE";//CDEBA
	int k = 0;
	scanf("%d",&k);
	left_rotate(arr, strlen(arr),k);
	printf("%s",arr);
	return 0;
}

//�����������в���ĳ���� 
struct coordinate//��������ṹ�壬�Ա㷵��ʱ����ֱ�ӷ��ؽṹ�����
{                //�Ӷ�ʵ��ͨ���ṹ������������Զ��庯������������ֵ
	int x;
	int y;
};

//���ﺯ���ķ�������Ҫ��coordinate�ṹ�����ͣ����������ڲ��ҵ�ĳ����ʱ
//�ܹ�ֱ�ӽ��丳ֵ���ṹ���Ա����󷵻ؽṹ�������ֵ��ע�������������
//����������coordinate�ṹ�����ͣ���������������ҲҪ��coordinate�ṹ������
//����������
struct coordinate research1(int(*p)[3], int k)
{
	struct coordinate c = { -1,-1 };//��ʼ����-1������
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		if (k < *(*(p + i) + 3))
		{
			c.x = i;//�������긳ֵ���ṹ���Աx
			for (j = 0; j < 3; j++)
			{
				if (*(*(p + i) + j) == k)
				{
					c.y = j;//�������긳ֵ���ṹ���Աy
				}
					
			}
		}
		
	}
	return c;//���ؽṹ�����
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	
	printf("��������Ҫ���ҵ�����");
	int k = 0;
	scanf("%d",&k);
	struct coordinate tem= research1(arr, k);//�ýṹ�����������
	if (tem.x!=-1&&tem.y!=-1)
	{
		printf("�ҵ���,�����ǣ�%d %d\n",tem.x,tem.y);
	}
	else
	{
		printf("û�ҵ�\n");
	}

	return 0;
}
int research2(int(*p)[3], int* x, int* y, int k)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < 3; i++)
	{
		if (k < *(*(p + i) + 3))
		{
			*x = i;
			for (j = 0; j < 3; j++)
			{
				if (*(*(p + i) + j) == k)
				{
					*y = j;
					return 1;
				}
						
			}
		}
			
	}
	return 0;
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;
	scanf("%d",&k);
	int x = 0;
	int y = 0;
	int len = research2(arr, &x, &y, k);
	if (1 == len)
	{
		printf("�ҵ��ˣ�������%d %d\n",x,y);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}
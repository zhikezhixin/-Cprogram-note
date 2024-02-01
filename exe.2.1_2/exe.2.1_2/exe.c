#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//左旋字符串
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

//在杨氏三角中查找某个数 
struct coordinate//定义坐标结构体，以便返回时可以直接返回结构体变量
{                //从而实现通过结构体变量来接收自定义函数传过来的数值
	int x;
	int y;
};

//这里函数的返回类型要是coordinate结构体类型，这样下面在查找到某个数时
//能够直接将其赋值给结构体成员，最后返回结构体变量，值得注意的是我们这里
//返回类型是coordinate结构体类型，所以在主函数中也要用coordinate结构体类型
//变量来接收
struct coordinate research1(int(*p)[3], int k)
{
	struct coordinate c = { -1,-1 };//初始化，-1不存在
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		if (k < *(*(p + i) + 3))
		{
			c.x = i;//将横坐标赋值给结构体成员x
			for (j = 0; j < 3; j++)
			{
				if (*(*(p + i) + j) == k)
				{
					c.y = j;//将纵坐标赋值给结构体成员y
				}
					
			}
		}
		
	}
	return c;//返回结构体变量
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	
	printf("请输入你要查找的数：");
	int k = 0;
	scanf("%d",&k);
	struct coordinate tem= research1(arr, k);//用结构体变量来接收
	if (tem.x!=-1&&tem.y!=-1)
	{
		printf("找到了,坐标是：%d %d\n",tem.x,tem.y);
	}
	else
	{
		printf("没找到\n");
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
		printf("找到了，坐标是%d %d\n",x,y);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

//内存拷贝函数
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	int arr2[20] = { 0 };
	memcpy(arr2, arr1, 28);
	int len = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ",arr2[i]);
	}

	return 0;
}

void* my_memcpy(void* dest, const void* sour, size_t num)
{
	assert(dest && sour);
	void* tem = dest;//记录目标空间起始地址，用于复制完成后返回目标空间起始地址。
	while (num--)
	{
		*(char*)dest = *(char*)sour;
		dest = (char*)dest + 1;
		sour = (char*)sour + 1;
		//将dest和sour强制转化为char*使得一次跳过一个字节
	}
	return tem;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 28);
	int len = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ",arr2[i]);
	}

	return 0;
}

void* my_memmove(void* dest, const void* sour, size_t num)
{
	assert(dest && sour);
	void* tem = dest;
	//目标空间在起始空间前面，从开头开始覆盖数值
	if (dest < sour)
	{
		while (num--)//循环条件
		{
			*((char*)dest)++ = *((char*)sour)++;
			
		}
	}
	//目标空间在起始空间后面，从末尾开始覆盖数值
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)sour + num);
			//直接跳到最后面，指针随循环次数的减少向前移动
		}
	}
	return tem;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	my_memmove(arr1 , arr1 + 1, 8);
	int len = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ",arr1[i]);
	}

	return 0;
}

//内存复制函数
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	int arr2[10] = { 0 };
	memcpy(arr2, arr1, 28);
	int len = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ",arr2[i]);
	}

	return 0;
}


//内存比较函数
int main()
{
	int arr1[] = { 1,3,17,9,4 };
	int arr2[] = { 1,3,7,9 };
	int tem;

    tem = memcmp(arr1, arr2, 12);
	printf("%d\n",tem);

	tem = memcmp(arr1, arr2, 8);
	printf("%d\n", tem);

	return 0;
}


int my_memcmp(const void* p1, const void* p2, size_t num)
{
	assert(p1&& p2);
	while (num--)
	{
		if (*((char*)p1) == *((char*)p2))
		{
			p1 = (char*)p1 + 1;
			p2 = (char*)p2 + 1;
		}
		else if(*((char*)p1) > *((char*)p2))
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "asdf346sfd";
	char arr2[] = "asde34";
	int tem;

	tem = my_memcmp(arr1, arr2, 3);
	printf("%d\n", tem);

	tem = memcmp(arr1, arr2, 4);
	printf("%d\n", tem);

	return 0;
}

//内存设置函数
int main()
{
	char arr[] = "hello world";
	memset(arr + 5, 'x', 6);
	printf("%s\n",arr);

	return 0;
}


void* my_memset(void* p, int val, size_t num)
{
	assert(p);
	void* tem = p;
	while (num--)
	{
		*((char*)p) = (char)val;
		p = (char*)p + 1;
	}
	return tem;
}

int main()
{
	char arr[] = "hello world";
	my_memset(arr + 5, '3686', 6);
	printf("%s\n", arr);

	return 0;
}
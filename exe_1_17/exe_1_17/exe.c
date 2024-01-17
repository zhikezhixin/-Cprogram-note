#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
#include <stdlib.h>


int cmp(const void* e1, const void* e2)
{
	return *((int*)e1) - *((int*)e2);
}

void Swap(char* e1, char* e2,int width)
{
	for (int i = 0; i < width; i++)
	{
		char tem = *e1;
		*e1 = *e2;
		*e2 = tem;
		e1++;
		e2++;
	}

}

void bsort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width)>0)//回调函数
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
		}
	}
}

int main()
{
	int arr[10] = { 2,3,6,7,5,9,0,1,4,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	printf("使用qsort进行排序:");
	qsort(arr,sz,sizeof(arr[0]),cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
	printf("使用bsort进行排序:");
	bsort(arr, sz, sizeof(arr[0]), cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");

	return 0;
}
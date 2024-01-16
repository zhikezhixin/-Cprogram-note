#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int compare(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
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

void Bubble_sort(void* base, int sz, int width, int(*compare)(const void* e1,const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if(compare((char*)base+j*width,(char*)base+(j+1)*width)>0);
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
		}
	}
}

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	Bubble_sort(arr, sz, sizeof(arr[0]), compare);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ",*(arr+i));
	}
	return 0;
}
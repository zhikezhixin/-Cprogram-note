#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
//判断一个字符串是否可以有另一个字符串左旋得到

int juge_left_rotate1(char* arr1, char* arr2)
{
	int len = strlen(arr1);
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++)
	{
		char tem = *arr1;
		for (j = 0; j < len; j++)
		{
			arr1[j] = arr1[j + 1];
		}
		arr1[j - 1] = tem;
		if (strcmp(arr1, arr2) == 0)
			return 1;
	}
	return 0;
}

int juge_left_rotate2(char* arr1, char* arr2)
{
	assert(arr1 && arr2);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0;
	strncat(arr1, arr1, 6);
	char* tem = strstr(arr1, arr2);
	if (tem == NULL)
		return 0;
	else
		return 1;


}

int main()
{
	char arr1[20] = "ABCDEF";
	char arr2[] = "CDEFAB";
	int tem = juge_left_rotate1(arr1, arr2);
	int tem = juge_left_rotate2(arr1, arr2);
	if (tem == 1)
	{
		printf("可以\n");
	}
	else
	{
		printf("不可以\n");
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//模拟strlen求字符串长度
int my_strlen(char* parr)
{
	char* str = parr;
	while (*parr != '\0')
	{
		parr++;
	}
	return (parr - str);
}

int main()
{
	char arr[] = "abcdefg";
	int len = my_strlen(arr);
	printf("%d\n",len);

	return 0;
}


//模拟strcpy拷贝字符串
char* my_strlen(char* parr2, char* parr1)
{
	assert(parr1 && parr2);
	char* str = parr2;
	while (*parr2++ = *parr1++)//赋值表达式返回被赋的值，当*parr1为\0时，赋给
		;                      //parr2之后循环条件为0（假），跳出循环
	return str;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[20] = { 0 };
	my_strlen(arr2, arr1);
	printf("%s\n",arr2);
	return 0;
}


//模拟strcmp比较字符串
int my_strcmp(const char* parr1,const char* parr2)
{
	assert(parr1 && parr2);
	for (; *parr1 == *parr2; parr1++ && parr2++)
	{
		if (*parr1 == '\0')
			return 0;
	}
	return *parr1 - *parr2;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcg";

	if (my_strcmp(arr1, arr2) > 0)
		printf("arr1大于arr2\n");

	else if (my_strcmp(arr1, arr2) == 0)
		printf("arr1等于arr2\n");

	else 
	    printf("arr1小于arr2\n");

	return 0;
}


//模拟实现strcat链接字符串
char* my_strcat(char* parr1, const char* parr2)
{
	assert(parr1 && parr2);
	char* str = parr1;
	while (*parr1 != '\0')
	{
		parr1++;
	}
	while (*parr1++ = *parr2++)
		;
	return str;
}

int main()
{
	char arr1[20] = "abc";
	char arr2[] = "def";
	my_strcat(arr1, arr2);

	printf("%s\n",arr1);
	return 0;
}
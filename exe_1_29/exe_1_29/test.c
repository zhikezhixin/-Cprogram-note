#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//字符串查找
int main()
{
	char arr1[20] = "how are you";
	char arr2[] = "are";
	char* tem = strstr(arr1, arr2);
	if (tem == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了\n");
	}

	return 0;
}
char* my_strstr(const char* parr1, const char* parr2)
{
	assert(parr1 && parr2);
	const char* p1 = parr1;
	const char* p2 = parr2;
	const char* p = parr1;
	while (*p)
	{
		p1 = p;
	    while ((*p1 != '\0') &&( *p2 != '\0' )&& (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return (char*) p;
		}
		p++;
		
	}
	return NULL;
}
int main()
{
	char arr1[20] = "how are you";
	char arr2[] = "are";
	char* tem = my_strstr(arr1, arr2);
	if (tem == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了\n");
	}
		
	return 0;
}


//字符串截断
int main()
{
	const char* div = "@.";
	char ch[] = "1625220574@qq.com";
	char* tem;
	for (tem = strtok(ch, div); *tem != "\0"; tem = strtok(NULL, div))
	{
		printf("%s\n",tem);
	}
	return 0;
}

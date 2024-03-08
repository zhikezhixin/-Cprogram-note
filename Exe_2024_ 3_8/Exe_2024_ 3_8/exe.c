#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//
//int main()
//{
//	long a = 0;
//	long b = 0;
//	while (scanf("%d %d", &a, &b) == 2)
//	{
//		long max = a > b ? a : b;
//		long min = a < b ? a : b;
//		long i = 0;
//		while (i = max%min)
//		{
//			max = min;
//			min = i;
//		}
//		
//		printf("最大公约数：%ld\n",min);
//		printf("最小公倍数：%ld\n",(a*b)/min);
//	}
//	return 0;
//}

/*int main()
{
	int a = 0;
	scanf("%d",&a);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (i == 0 || i == a - 1 || j == 0 || j == a - 1)
			{
				printf(" * ");
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
	return 0;
}*/
#include <stdlib.h>
#include <string.h>
#include <errno.h>
struct S
{
	int a;
	int arr[];
};
int main()
{
	/*int sz = sizeof(struct S);
	printf("%d\n",sz);*/
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 40);
	if (ps == NULL)
	{
		printf("%s\n",strerror(errno));
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	ps->a = 40;
	printf("扩容前：\n");
	printf("a = %d \n arr = ",ps ->a);
	for (i = 0; i < 10; i++)
	{
		printf(" %d",ps->arr[i]);
	}
	printf("\n");
	struct S* tem = realloc(ps, sizeof(struct S) + 80);
	if (tem != NULL)
	{
		ps = tem;
	}
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	ps->a =80;
	printf("扩容后：\n");
	printf("a = %d \n arr = ", ps->a);
	for (i = 10; i < 20; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 20; i++)
	{
		printf(" %d", ps->arr[i]);
	}


	free(ps);
	ps = NULL;
	return 0;
}
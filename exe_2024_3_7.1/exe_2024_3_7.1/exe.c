#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//
//enum day
//{
//	mon = 1,
//	tuse,
//	wed,
//	thur,
//	fri,
//	sat,
//	sun,
//
//};
//
//int main()
//{
//	enum day d;
//	int input;
//	scanf("%d",&input);
//	switch (input)
//	{
//	case mon:
//		printf("%d\n",mon);
//		break;
//	case tuse:
//		printf("%d\n",tuse);
//		break;
//	case wed:
//		printf("%d\n", wed);
//		break;
//	case thur:
//		printf("%d\n", thur);
//		break;
//	default:
//		break;
//	}
//	return 0;
//}
//
//union Un
//{
//	int a;
//	char b;
//};
//
//int main()
//{
//	union Un u;
//	printf("%d\n",sizeof(u));
//	printf("%p\n",&u);
//	printf("%p\n", &(u.a));
//	printf("%p\n", &(u.b));
//
//	u.a = 10;//00 00 10 10
//	         //11 11 01 01
//	         //11 11 01 10
//	printf("%d\n",u.a);
//	u.b = 2;//00 00 00 10
//	        //11 11 11 01
//	        //11 11 11 10
//            //11 11 11 10
//
//	return 0;
//}

//测试计算机是小端存储还是大端存储

//int test()
//{
//	union
//	{
//		int i;
//		char c;
//	}u;
//	u.i = 1;     
//	return u.c;  
//}
//
//int main()
//{
//	int tem = 0;
//	tem = test();//大端；00 00 00 01
//	if (tem == 1)//小端；01 00 00 00
//	{
//		printf("小端%d\n",tem);
//	}
//	else
//	{
//		printf("大端：%d\n",tem);
//	}
//
//
//	return 0;
//}
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//int* p = (int*)malloc(40);
//	 int* p = (int*)calloc(10,4);
//    if (p == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	printf("扩容前：");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", * (p + i));
//	}
//	printf("\n");
//	printf("p扩容前的地址是%p\n",&p);
//	int* tem = realloc(p, 80000);
//	if (tem != NULL)
//	{
//		p = tem;
//	}
//	for (i = 10; i < 20; i++)
//	{
//		*(p + i) = i;
//	}
//	printf("扩容后：");
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	printf("p扩容后的地址%p\n",&p);
//	free(p);
//	p = NULL;
//	return 0;
//}
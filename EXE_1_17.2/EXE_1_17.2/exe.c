#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//在x64环境下地址是8字节
// 在x84环境下地址是4字节
int main()
{
	int a[] = { 1,2,3,4 };

	printf("%d\n", sizeof( a ));//16

	printf("%d\n",sizeof( a + 0));//  4/8

	printf("%d\n", sizeof( *a ));// 4

	printf("%d\n", sizeof(a + 1));// 4/8

	printf("%d\n", sizeof(a[1]));// 4

	printf("%d\n", sizeof(&a));// 4/8

	printf("%d\n", sizeof(*&a));// 16
	// &a取得了整个数组的地址，在对其进行解引用就得到了整个数组，*&a就相当于单独的a
	printf("%d\n", sizeof(&a+1));// 4/8

	printf("%d\n", sizeof(&a[0]));// 4/8

	printf("%d\n", sizeof(&a[0]+1));// 4/8

	return 0;
}

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };

	printf("%d\n",sizeof(arr));// 6

	printf("%d\n", sizeof(arr+0));// 4/8

	printf("%d\n", sizeof(*arr));// 1

	printf("%d\n", sizeof(arr[1]));// 1
	
	printf("%d\n", sizeof(&arr));// 4/8
	//&arr取出了arr的地址，既然是地址那一定就是4或者8字节
	printf("%d\n", sizeof(&arr[0]+1));// 4/8


	return 0;
}

int main()
{
	char arr[] = {'a','b','c','d','e','f'};

	printf("%d\n",strlen(arr));// 随机值，假设为a

	printf("%d\n",strlen(arr+0));// 随机值

	printf("%d\n", strlen(*arr ));// 报错，野指针

	printf("%d\n", strlen(arr[1]));// 报错，野指针

	printf("%d\n", strlen(&arr ));// 随机值

	printf("%d\n", strlen(&arr+1));// a-6

	printf("%d\n", strlen(&arr[0]+1));// a-1

	return 0;
}

int main()
{
	char arr[] = "abcdef";

	printf("%d\n", sizeof(arr));// 7
	
    printf("%d\n", sizeof(arr+0));// 4/8
	
	printf("%d\n", sizeof(*arr ));// 1
	
	printf("%d\n", sizeof(arr[1]));// 1

	printf("%d\n", sizeof(&arr ));// 4/8

	printf("%d\n", sizeof(&arr+1));// 4/8
	
	printf("%d\n", sizeof(&arr[0]+1));// 4/8
	
	return 0;
}

int main()
{
	char* p = "abcdef";

	printf("%d\n",sizeof(p));// 7

	printf("%d\n", sizeof(p+1));// 4/8

	printf("%d\n", sizeof(*p));// 1
	//p中存放着字符串首地址，则单独的p就是a的地址
	//就好比把10赋给a（a=10）,则单独的a就是10

	printf("%d\n", sizeof(p[0]));// 1

	printf("%d\n", sizeof(&p));// 4/8

	printf("%d\n", sizeof(&p+1));// 4/8

	printf("%d\n", sizeof(&p[0] + 1));// 4/8

	printf("%d\n", strlen(p));// 6

	printf("%d\n", strlen(p + 1));// 5

	printf("%d\n", strlen(*p));// 错误，野指针

	printf("%d\n", strlen(p[0]));// 错误，野指针

	printf("%d\n", strlen(&p));// 随机值

	printf("%d\n", strlen(&p[0] + 1));//5 

	return 0;
}


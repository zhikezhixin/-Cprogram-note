#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//��x64�����µ�ַ��8�ֽ�
// ��x84�����µ�ַ��4�ֽ�
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
	// &aȡ������������ĵ�ַ���ڶ�����н����þ͵õ����������飬*&a���൱�ڵ�����a
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
	//&arrȡ����arr�ĵ�ַ����Ȼ�ǵ�ַ��һ������4����8�ֽ�
	printf("%d\n", sizeof(&arr[0]+1));// 4/8


	return 0;
}

int main()
{
	char arr[] = {'a','b','c','d','e','f'};

	printf("%d\n",strlen(arr));// ���ֵ������Ϊa

	printf("%d\n",strlen(arr+0));// ���ֵ

	printf("%d\n", strlen(*arr ));// ����Ұָ��

	printf("%d\n", strlen(arr[1]));// ����Ұָ��

	printf("%d\n", strlen(&arr ));// ���ֵ

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
	//p�д�����ַ����׵�ַ���򵥶���p����a�ĵ�ַ
	//�ͺñȰ�10����a��a=10��,�򵥶���a����10

	printf("%d\n", sizeof(p[0]));// 1

	printf("%d\n", sizeof(&p));// 4/8

	printf("%d\n", sizeof(&p+1));// 4/8

	printf("%d\n", sizeof(&p[0] + 1));// 4/8

	printf("%d\n", strlen(p));// 6

	printf("%d\n", strlen(p + 1));// 5

	printf("%d\n", strlen(*p));// ����Ұָ��

	printf("%d\n", strlen(p[0]));// ����Ұָ��

	printf("%d\n", strlen(&p));// ���ֵ

	printf("%d\n", strlen(&p[0] + 1));//5 

	return 0;
}


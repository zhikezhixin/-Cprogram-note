#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp_int(const void* e1, const void* e2)//注意这里必须写成const void*类型，因为作者当初在设计时就
                                           //是这么规定的，后面进行比较操作时再强制类型转化成我们需要的类型
{
	return (*(int*)e1 - *(int*)e2);//先强制类型转换成int*指针，再进行解引用后相减
}
struct stu
{
	char name[20];
	int age;
};

int cmp_name(const void* e1, const void* e2)//比较字符串方式的函数
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
	//strcmp返回值正好是>0,<0;=0;
}

int cmp_age(const void* e1, const void* e2)//比较整形方式函数
{
	return (((struct stu*)e1)->age - ((struct stu*)e2)->age);
}

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	struct stu p[3] = { {"fangrui",20},{"sunjin",19},{"panlei",28} };
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	   //(数组首地址，数组元素个数，一个元素大小，比较方式函数地址）
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
	int len = sizeof(p) / sizeof(p[0]);
	qsort(p, len, sizeof(p[0]), cmp_name);
	printf("根据名字排序:\n");
	for (i = 0; i < 3; i++)
	{
		printf("姓名:%s 年龄:%d \n", p[i].name,p[i].age);
	}

	printf("根据年龄排序:\n");
	qsort(p, len, sizeof(p[0]), cmp_age);
	for (i = 0; i < 3; i++)
	{
		printf("姓名:%s 年龄:%d \n", p[i].name, p[i].age);
	}
	printf("\n");

	return 0;
}
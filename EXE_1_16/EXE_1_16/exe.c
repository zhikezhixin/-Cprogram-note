#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp_int(const void* e1, const void* e2)//ע���������д��const void*���ͣ���Ϊ���ߵ��������ʱ��
                                           //����ô�涨�ģ�������бȽϲ���ʱ��ǿ������ת����������Ҫ������
{
	return (*(int*)e1 - *(int*)e2);//��ǿ������ת����int*ָ�룬�ٽ��н����ú����
}
struct stu
{
	char name[20];
	int age;
};

int cmp_name(const void* e1, const void* e2)//�Ƚ��ַ�����ʽ�ĺ���
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
	//strcmp����ֵ������>0,<0;=0;
}

int cmp_age(const void* e1, const void* e2)//�Ƚ����η�ʽ����
{
	return (((struct stu*)e1)->age - ((struct stu*)e2)->age);
}

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	struct stu p[3] = { {"fangrui",20},{"sunjin",19},{"panlei",28} };
	int sz = sizeof(arr) / sizeof(arr[0]);//��������Ԫ�ظ���
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	   //(�����׵�ַ������Ԫ�ظ�����һ��Ԫ�ش�С���ȽϷ�ʽ������ַ��
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
	int len = sizeof(p) / sizeof(p[0]);
	qsort(p, len, sizeof(p[0]), cmp_name);
	printf("������������:\n");
	for (i = 0; i < 3; i++)
	{
		printf("����:%s ����:%d \n", p[i].name,p[i].age);
	}

	printf("������������:\n");
	qsort(p, len, sizeof(p[0]), cmp_age);
	for (i = 0; i < 3; i++)
	{
		printf("����:%s ����:%d \n", p[i].name, p[i].age);
	}
	printf("\n");

	return 0;
}
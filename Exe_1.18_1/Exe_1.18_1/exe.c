#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n ",sizeof(a));// 48

	printf("%d\n ", sizeof(a[0][0]));// 4

	printf("%d\n ", sizeof(a[0])) ;//16
	//a[0]�����һ��Ԫ���������������ŵ�sizeof�ڲ���ʾ����һά����
	printf("%d\n ", sizeof(a[0]+1));// 4/8
	 
	printf("%d\n ", sizeof(*(a[0]+1))); //4
	//a[0]�����һ��Ԫ������������һ�õ���һ�еڶ���Ԫ�صĵ�ַ�������ú�õ�����Ԫ��
	printf("%d\n ", sizeof(a + 1));// 4/8

	printf("%d\n ", sizeof(*(a + 1)));// 16

	printf("%d\n ", sizeof(&a[0]+1));// 4/8

	printf("%d\n ", sizeof(*a));// 16

	printf("%d\n ", sizeof(a[3]));// 16

	return 0;
}
 

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	//&aȡ�����������ַ����һ�������������飬��ʱptrָ��������ĩβ
	printf("%d %d\n", *(a + 1), *(ptr - 1));// 2  5
	//û��ȡ��ַ�ĵ���a������Ԫ�ص�ַ����һ��ָ��ڶ���Ԫ�ص�ַ
	return 0;
}


//����p��ֵΪ0x100000�����±��ʽֵ�ֱ�Ϊ���٣�
//��֪�ṹ��stu���ͱ�����СΪ20�ֽ�
struct stu
{
	char* pcname;
	short sdate;
	char cha[2];
	short sba[4];
}*p=(struct stu*)0x100000;
int main()
{
	printf("%p\n",p+0x1);//0x100014
	//p��һ���ṹ��ָ�룬��һ������һ���ṹ���С��20�ֽڣ�
	printf("%p\n",(unsigned long)p+0x1);//0x100001
	//pǿ��ת�����޷��ų����ͣ�ʮ���Ƶ�����������һ�൱����������һ
	printf("%p\n",(unsigned int*)p + 0x1);//0x100004
	//unsigned int*ռ�ĸ��ֽڣ���ʱp��һ�����ĸ��ֽ�
	return 0;
}


int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	//aǿ��ת�������ͺ��һ�����൱����a��ַ�ϼ�һ�����൱�ڽ�ָ�����һ���ֽ�
	//(int)a + 1������仰����˼������ָ�����һ���ֽ�
	printf("%x, %x\n",ptr1[-1],*ptr2);//4 2000000
	return 0;
}


int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//{}���Ƕ��ű��ʽ���������ʽ��ʵ����int a[3][2] = { 1, 3, 5 }
	int* p;
	p = a[0];//a[0]�ǵ�һ�е�ַ
	printf("%d\n",p[0]);//1

	return 0;
}


int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	//����ָ����ָ������õ�����ָ��֮���Ԫ�ظ���
	printf("%p, %d\n",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);//FFFFFFFC  -4
	//-4��ԭ��:1000000000000000000000000000100
	//    ����:1111111111111111111111111111011
	//    ����:1111 1111 1111 1111 1111 1111 1111 1100
	//16���Ʊ�ʾ:F  F    F     F    F   F    F    C
	// ����%p��16���ƴ�ӡ��ַ�������ڴ�����ʲô���ͽ���������ַ��ӡ����
	// ��˽�-4���ڴ��д�Ĳ�����16���ƴ�ӡ����
	//p[4][2]�൱��*(*(p+4)+2)
	//��Ϊp��int��*��[4]���ͣ�����p��һ���������ĸ�����
	return 0;
}


int main()
{
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d ,%d\n",*(ptr1 - 1),*(ptr2 - 1));//10  5

	return 0;
}


int main()
{
	char* a[] = { "work", "at", "alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n",*pa);

	return 0;
}


int main()
{

	char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;

	printf("%s\n",**++cpp);
	printf("%s\n",*--*++cpp + 3);
	printf("%s\n",*cpp[-2] + 3);
	printf("%s\n",cpp[-1][-1]+1);

	return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n ",sizeof(a));// 48

	printf("%d\n ", sizeof(a[0][0]));// 4

	printf("%d\n ", sizeof(a[0])) ;//16
	//a[0]代表第一行元素数组名，单独放到sizeof内部表示整个一维数组
	printf("%d\n ", sizeof(a[0]+1));// 4/8
	 
	printf("%d\n ", sizeof(*(a[0]+1))); //4
	//a[0]代表第一行元素数组名，加一得到第一行第二个元素的地址，解引用后得到的是元素
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
	//&a取出整个数组地址，加一后跳过整个数组，此时ptr指针在数组末尾
	printf("%d %d\n", *(a + 1), *(ptr - 1));// 2  5
	//没有取地址的单独a代表首元素地址，加一后指向第二个元素地址
	return 0;
}


//假设p的值为0x100000。如下表达式值分别为多少？
//已知结构体stu类型变量大小为20字节
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
	//p是一个结构体指针，加一后跳过一个结构体大小（20字节）
	printf("%p\n",(unsigned long)p+0x1);//0x100001
	//p强制转换成无符号长整型（十进制的正数），加一相当于是整数加一
	printf("%p\n",(unsigned int*)p + 0x1);//0x100004
	//unsigned int*占四个字节，这时p加一跳过四个字节
	return 0;
}


int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	//a强制转化成整型后加一，就相当于在a地址上加一，就相当于将指针后移一个字节
	//(int)a + 1所以这句话的意思就是让指针后移一个字节
	printf("%x, %x\n",ptr1[-1],*ptr2);//4 2000000
	return 0;
}


int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//{}中是逗号表达式，所以这个式子实际上int a[3][2] = { 1, 3, 5 }
	int* p;
	p = a[0];//a[0]是第一行地址
	printf("%d\n",p[0]);//1

	return 0;
}


int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	//首先指针与指针相减得到的是指针之间的元素个数
	printf("%p, %d\n",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);//FFFFFFFC  -4
	//-4的原码:1000000000000000000000000000100
	//    反码:1111111111111111111111111111011
	//    补码:1111 1111 1111 1111 1111 1111 1111 1100
	//16进制表示:F  F    F     F    F   F    F    C
	// 由于%p以16进制打印地址，所以内存存的是什么它就将其视作地址打印出来
	// 因此将-4在内存中存的补码以16进制打印出来
	//p[4][2]相当于*(*(p+4)+2)
	//因为p是int（*）[4]类型，所以p加一跳过跳过四个整形
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



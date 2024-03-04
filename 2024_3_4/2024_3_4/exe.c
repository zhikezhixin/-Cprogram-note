#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h>
struct S1
{
	int a;
	char b;
	int c;
};
struct S2
{
	double d;
	struct S1 e;
	char f;
};

int main()
{
	printf("%d\n",offsetof(struct S2,d));
	printf("%d\n", offsetof(struct S2, e.a));
	printf("%d\n", offsetof(struct S2, e.b));
	printf("%d\n", offsetof(struct S2, e.c));
    printf("%d\n", offsetof(struct S2, f));


	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//带n的字符串函数
int main()
{
	char arr1[20] = "abcdef";
	char arr2[20] = { 0 };

	strncpy(arr2, arr1, 6);
	printf("arr2= %s\n",arr2);

	int len = strncmp(arr1, arr2, 6);
	if (0 == len)
		printf("==\n");

	strncat(arr1, arr2, 3);
	printf("arr1= %s\n",arr1);

	return 0;
}
#include <math.h>
int main()
{
	int input = 0;
	int i = 0;
	int count = 0;
	int sum = 0;
	int n = 0;
	scanf("%d",&input);
	while (input)
	{
		count = input % 10;
		input /= 10;
		if (count % 2 == 0)
			n = 0;
		else
			n = 1;
		sum += n * pow(10, i++);
		
	}

	printf("%d\n",sum);
	return 0;
}


//直角三角形
int main()
{
	int i = 0;
	int j = 0;
	int input = 0;
	scanf("%d",&input);

	for (i = 0; i < input; i++)
	{
		for (j = input - 1 - i; j >0; j--)
		{
			printf(" ");
		}
		for (j = 1 ; j <= i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

int main()
{
	int i = 1;
	int j = 1;
	int input = 0;
	while (scanf("%d", &input) == 1)
	{
		for (i = 1; i <= input; i++)
		{
			for (j = 1; j <= input; j++)
			{
				if (i + j <= input)
				{
					printf("   ");
				}
				else
				{
					printf(" * ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}

// scanf的返回值
int main()
{
	int n = 0;
	char ch = 0;
	int tem = scanf("%d %c",&n,&ch);
	

	printf("%d \n",tem);
}

int main()
{
	double value = 0.0;
	int month = 0;
	int day = 0;
	int tem = 0;
	float bargon = 1.0;
	scanf("%lf %d %d %d",&value,&month,&day,&tem);

	if (month == 11 && day == 11)
	{
		bargon = 0.7;
	}
	else if (month == 12 && day == 12)
	{
		bargon = 0.8;
	}

	value = value * bargon - tem * 50;

	if (value < 0.0)
		printf("%d",0);
	else
	printf("%.2lf\n",value);

	return 0;
}

int main()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	printf("%d %d",a + b, c);// 300    44
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c<= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3) == 1 &&
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(c == 5) + (d == 3) == 1 &&
							(e == 4) + (a == 1) == 1)
						{
							if (a * b * c * d * e == 120)
							{
								printf("a=%d b=%d c=%d d=%d e=%d\n",
									a,b,c,d,e);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
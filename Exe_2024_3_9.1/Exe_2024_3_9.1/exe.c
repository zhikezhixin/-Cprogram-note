#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
#include <errno.h>
#include <string.h>


struct S
{
	int a;
	char b;
};
int main()
{
	struct S s = { 1,'c' };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n",strerror(errno));
		return 1;
	}
	//����ַ�
	/* char  i = 0;
	for (i = 'a'; i <= 'z'; i++)
	{
		fputc(i,pf);
	}*/
	//�����ַ�
	/*char ch = fgetc(pf);
	printf("%c ",ch);
	ch = fgetc(pf);
	printf("%c ", ch);
	ch = fgetc(pf);
	printf("%c ", ch);*/
	/*int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		printf("%c ",ch);
	}*/
	//����ַ���
	//fputs("hello wrold\n",pf);
	//�����ַ���
	/*char arr[24];
	fgets(arr,240,pf);
	printf("%s\n",arr);*/
	fprintf(stdout,"%d %c\n",s.a,s.b);
	fclose(pf);
	pf = NULL;
	return 0;
}
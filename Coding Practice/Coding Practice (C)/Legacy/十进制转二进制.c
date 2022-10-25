#include<stdio.h>
int main()
{
	int ten,two;
	printf("请输入十进制数字：");
	scanf("%d",&ten);
	printf("                                                                   ");
	while (ten>=1)
	{
		printf("%d\b\b",(ten%2));
		ten=(int)(ten/2);
	}
	return 0;
 } 

#include<stdio.h>
int main()
{
	int a=0;
	scanf("%d",&a);       //无用
	printf("%d\n",a);      //无用
	int b[]={9,8,7,6,5,4,3,2,1};
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9-i-1;j++)
		{
			if(b[j]>b[j+1])
			{
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
		for(int k=0;k<9;k++)
		{
			printf("%d",b[k]);
		}
		printf("\n");
	}
	printf("Hello World!!\n");      //无用
	return 0;
}

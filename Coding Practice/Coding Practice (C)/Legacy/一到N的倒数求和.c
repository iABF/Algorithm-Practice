#include<stdio.h>
int main()
{
	double deno=2.0,sum=1.0,term;
	int n,s=1;
	printf("����N��ֵ\n"); 
	scanf("%d",&n);
	while (deno<=n)
	{
		term=s/deno;
		sum=sum+term;
		deno=deno+1;
	}
	printf("��(1/n)=%f\n",sum);
	return 0;
}

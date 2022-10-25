#include<stdio.h> 
int main()
{
	long int a=0,sum=0,n=0;
	while(scanf("%ld",&a)==1)
	{
		if(getchar()=='\n')
		{
			sum=sum+a; 
			goto print;
		}
		sum=sum+a;
		while(1)
		{
			scanf("%ld",&a);
			sum=sum+a;
			if(getchar()=='\n')break;
		}
		print:printf("%ld\n",sum);
		sum=0;
		a=0;
	}
	return 0;
}

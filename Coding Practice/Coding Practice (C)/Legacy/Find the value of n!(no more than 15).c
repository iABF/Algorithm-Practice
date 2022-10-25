#include<stdio.h>
int main()
{
	int i,t,n;
	printf("请输入n的值（n不超过15）\n");
	scanf("%d",&n);
	t=1;
	i=2;
	while(i<=n)
	{
		t=t*i;
		i=i+1;
	}
	printf("n!=%d\n",t);
	return 0;
 } 

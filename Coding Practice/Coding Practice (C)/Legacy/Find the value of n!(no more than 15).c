#include<stdio.h>
int main()
{
	int i,t,n;
	printf("������n��ֵ��n������15��\n");
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

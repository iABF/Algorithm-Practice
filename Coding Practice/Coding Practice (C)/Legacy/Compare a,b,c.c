#include<stdio.h>
int main()
{
	int max(int x,int y);
	int a,b,c,d,e;
	scanf("%d %d %d",&a,&b,&c);
	d=max(a,b);
	e=max(c,d);
	printf("max=%d\n",e);
	return 0;
 } 
 int max(int x,int y)
 {
 	int z;
 	if(x>y)z=x;
 	else z=y;
 	return z;
 }

#include<stdio.h>
#include<math.h>
int main()
{
	double d,p,r,m;
	printf("请输入贷款总额：");
	scanf("%lf",&d);
	printf("请输入每月还款额：");
	scanf("%lf",&p);
	r=0.01;
	m=(log(p/(p-d*r)))/(log(1+r));
	printf("还清月数m=%7.1f",m);
	return 0;
}

 

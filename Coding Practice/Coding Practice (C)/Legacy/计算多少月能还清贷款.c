#include<stdio.h>
#include<math.h>
int main()
{
	double d,p,r,m;
	printf("����������ܶ");
	scanf("%lf",&d);
	printf("������ÿ�»���");
	scanf("%lf",&p);
	r=0.01;
	m=(log(p/(p-d*r)))/(log(1+r));
	printf("��������m=%7.1f",m);
	return 0;
}

 

#include<stdio.h>
#include<math.h>
int main()
{
	printf("Hello World!\n");               //No.1
	double n,S=0,result,k=1,one=1,l;        //No.2
	printf("������������n��");
	scanf("%lf",&n);
	while(k<=n)
	{
		l=pow(n,one/k);
		S=S+l;
		k=k+1;
	}
	result=S/n;
	printf("(n^(1/1)+n^(1/2)+......+n^(1/n))/n=%23.20f\n",result);
	int t,c;                                //No.3
	printf("������ʮ����������t��");
	scanf("%d",&t);
	printf("t�Ķ����Ʊ�ʾΪ��                         ");
	while(t>=1)
	{
		c=t%2;
		printf("%d\b\b",c);
		t=(int)(t/2);
	}
	printf("\n");
	return 0;
}

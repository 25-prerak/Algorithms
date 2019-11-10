#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a,b,c;
	int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;	
	printf("Enter the cost of item\n");
	scanf("%d",&a);
	printf("Enter money\n");
	scanf("%d",&b);
	c=b-a;
	if(c<0)
	{
		printf("Not possible\n");
		exit(-1);
	}					
	c1 = c/100000;
	printf("100000: %d\n",c1);	
	c=c%100000;
	c2=c/50000;
	printf("50000: %d\n",c2);	
	c=c%50000;
	c3=c/20000;
	printf("20000: %d\n",c3);	
	c=c%20000;
	c4=c/10000;
	printf("10000: %d\n",c4);	
	c=c%10000;
	c5=c/5000;
	printf("5000: %d\n",c5);	
	c=c%5000;
	c6=c/2000;
	printf("2000: %d\n",c6);	
	c=c%2000;
	c7=c/1000;
	printf("1000: %d\n",c7);	
	c=c%1000;
	c8=c/500;
	printf("500: %d\n",c8);	
	c=c%500;
	c9=c/200;
	printf("200: %d\n",c9);	
	c=c%200;
	c10=c/100;
	printf("100: %d\n",c10);	
	c=c%200;
	printf("No. of notes are %d\n",(c1+c2+c3+c4+c5+c5+c6+c7+c8+c9+c10));
}

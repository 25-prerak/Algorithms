#include<stdio.h>
#include<conio.h>
#include<math.h>

void func(float a, float b, float c, float d, float e, float *s, float *av, float *ssd)
{
float temp;
*s=a+b+c+d+e;            /* sum of digits */
*av=(a+b+c+d+e)/5.0;       /* average */
a=a-(*av);
b=b-(*av);
c=c-(*av);
d=d-(*av);
e=e-(*av);
temp=((a*a)+(b*b)+(c*c)+(d*d)+(e*e))/4.0;           /* standard deviation */
*ssd=sqrt(temp);
}
int main()
{
float d1,d2,d3,d4,d5,sum;
float avg,sd;
printf("enter five digits: \n\n");
scanf("%f%f%f%f%f",&d1,&d2,&d3,&d4,&d5);
func(d1,d2,d3,d4,d5,&sum,&avg,&sd);
printf("\tsum = %f\n\taverage = %f\n\tstandard deviation = %f ",sum,avg,sd);
return 0;
}

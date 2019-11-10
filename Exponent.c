#include <stdio.h>
int exp(int x,int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*x;
    return f;
}

int dc_exp(int x,int n)
{
    int r;
    if(n==0)
        return 1;
    r=dc_exp(x,(n/2));
    if((n%2)==0)
        return (r*r);
    else
        return (x*r*r);
}
int main()
{
    int x,n;
    printf("Enter no.\n");
    scanf("%d",&x);
    printf("Enter exponent\n");
    scanf("%d",&n);
    printf("(Naive method)%d raise to %d is %d\n",x,n,exp(x,n));
    printf("(Divide and conquer)%d raise to %d is %d",x,n,dc_exp(x,n));

}

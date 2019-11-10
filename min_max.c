#include <stdio.h>
int mn(int [],int);
int mx(int [],int);
int main()

{
	int a[100];
	int n,max,min,i;
	printf("Enter the Number of elements \n");
	scanf("%d", &n);
	printf("Enter elements : \n");
	for(i=0;i<n;i++)
	{scanf("%d",&a[i]);}
	max=mx(a,n);
	printf("\nMAXIMUM NUMBER IS %d \n",max);
	min=mn(a,n);
	printf("\nMINIMUM NUMBER IS %d \n",min);
	return 0;
}


int mx(int x[],int k)

{
	int z,i;
	z=x[0];
	for(i=1;i<k;i++)
	{
	if(x[i]>z)
	z=x[i];
	}
	return(z);
}


int mn(int x[],int k)

{	int w,i;
 	w=x[0];
	for(i=1;i<k;i++)
        {
        if(x[i]<w)
        w=x[i];
        }
        return(w);
}

#include <stdio.h>

int dotproduct(int a[100] , int b[100] , int n)
{       int i,p=0;
        for( i = 0 ; i < n ; i++ )
        {p = p + a[i] * b[i] ;}
        return p;
}
int main()
{
	int a[100];
	int b[100];
	int n,i;
	printf("Enter the number of directions in the vectors \n");
	scanf("%d",&n);
	printf("Enter magnitudes of first vector in different directions \n");
	for(i = 0; i < n ; i++ )
	{scanf("%d",&a[i]);}
	printf("Enter magnitudes of second vector in different directions \n");
        for(i = 0; i < n ; i++ )
        {scanf("%d",&b[i]);}
	printf("The dot product of the two vectors is \n");
	printf("%d",dotproduct(a , b ,n ));
	
	return 0;
}



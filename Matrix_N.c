#include<stdio.h>
void build_matrix(int r1,int c1,int a[r1][c1])
{
	printf("Enter elements for Matrix\n");
	for(int i=0;i<r1;i++)
		for(int j=0;j<c1;j++)
			{
				printf("Enter element for %d row %d column\n",i+1,j+1);
				scanf("%d",&a[i][j]);	 	
			}
}
void display_matrix(int r1,int c1,int a[r1][c1])
{
	for(int i=0;i<r1;i++)
		{
		for(int j=0;j<c1;j++)
			printf("%d ",a[i][j]);
		printf("\n");	
		}		
}
void multiply(int r1,int c1,int r2,int c2,int a[r1][c1],int b[r2][c2],int c[r1][c2])
{
	for(int i=0;i<r1;i++)
		for(int j=0;j<c2;j++)
			{
			c[i][j]=0;			
			for(int k=0;k<c1;k++)
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
}
void main()
{
	int r1,r2,c1,c2;
	printf("Enter row of matrix 1\n");
	scanf("%d",&r1);
	printf("Enter column of matrix 1\n");
	scanf("%d",&c1);
	printf("Enter row of matrix 2\n");
	scanf("%d",&r2);
	printf("Enter column of matrix 2\n");
	scanf("%d",&c2);
	int a[r1][c1],b[r2][c2];
	build_matrix(r1,c1,a);
	build_matrix(r2,c2,b);
	if(c1==r2)
	{
		int c[r1][c2];
		multiply(r1,c1,r2,c2,a,b,c);
		printf("Matrix after multiplcation\n");
		display_matrix(r1,c2,c);
	}
	else
		printf("Multiplpication not possible\n");
}

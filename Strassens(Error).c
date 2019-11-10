// Code has errors. After addition a11,a12.../p1,p2... gets modified and that modified one is used in further calculations.

#include<stdio.h>
void build_matrix(int n,int a[n][n])
{
	printf("Enter elements for Matrix\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
				printf("Enter element for %d row %d column\n",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
}
void display_matrix(int n,int a[n][n])
{
	for(int i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
		}
}
void copy(int n,int a[n][n],int b[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
                a[i][j]=b[i][j];
			}
}
void add(int n,int a[n][n],int b[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
                a[i][j]=a[i][j]+b[i][j];
			}
}
void sub(int n,int a[n][n],int b[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
                a[i][j]=a[i][j]-b[i][j];
			}
}
void multiply(int n,int a[n][n],int b[n][n],int c[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
			c[i][j]=0;
			for(int k=0;k<n;k++)
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
}
void assign(int n,int a[n][n],int b[n][n])
{
     int k=n/2;
     int a11[k][k],a12[k][k],a21[k][k],a22[k][k],b11[k][k],b12[k][k],b21[k][k],b22[k][k];
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                {
                    a11[i][j]=a[i][j];
                    b11[i][j]=b[i][j];
                }
        for(int i=0,x=0;i<k,x<k;i++,x++)
            for(int j=k,y=0;j<n,y<k;j++,y++)
                {
                    a12[x][y]=a[i][j];
                    b12[x][y]=b[i][j];
                }
        for(int i=k,x=0;i<n,x<k;i++,x++)
            for(int j=0,y=0;j<k,y<k;j++,y++)
                {
                    a21[x][y]=a[i][j];
                    b21[x][y]=b[i][j];
                }
        for(int i=k,x=0;i<n,x<k;i++,x++)
            for(int j=k,y=0;j<n,y<k;j++,y++)
                {
                    a22[x][y]=a[i][j];
                    b22[x][y]=b[i][j];
                }

}
void s_multiply(int n,int a[n][n],int b[n][n],int c[n][n])
{
    if(n==2)
    {
        int a11,a12,a21,a22,b11,b12,b21,b22,p1,p2,p3,p4,p5,p6,p7,c11,c12,c21,c22;
        a11=a[0][0],a12=a[0][1],a21=a[1][0],a22=a[1][1];
        b11=b[0][0],b12=b[0][1],b21=b[1][0],b22=b[1][1];
        p1=(a11+a22)*(b11+b22);
        p2=(a21+a22)*b11;
        p3=a11*(b12-b22);
        p4=a22*(b21-b11);
        p5=(a11+a12)*b22;
        p6=(a21-a11)*(b11+b12);
        p7=(a12-a22)*(b21+b22);
        c11=p1+p4-p5+p7;
        c12=p3+p5;
        c21=p2+p4;
        c22=p1+p3-p2+p6;
        c[0][0]=c11;
        c[0][1]=c12;
        c[1][0]=c21;
        c[1][1]=c22;
    }
    else
    {
        int k;
        k=n/2;
        int p1[k][k],p2[k][k],p3[k][k],p4[k][k],p5[k][k],p6[k][k],p7[k][k];
        int c11[k][k],c12[k][k],c21[k][k],c22[k][k];
      /*
        int a11[k][k],a12[k][k],a21[k][k],a22[k][k],b11[k][k],b12[k][k],b21[k][k],b22[k][k];
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                {
                    a11[i][j]=a[i][j];
                    b11[i][j]=b[i][j];
                }
        for(int i=0,x=0;i<k,x<k;i++,x++)
            for(int j=k,y=0;j<n,y<k;j++,y++)
                {
                    a12[x][y]=a[i][j];
                    b12[x][y]=b[i][j];
                }
        for(int i=k,x=0;i<n,x<k;i++,x++)
            for(int j=0,y=0;j<k,y<k;j++,y++)
                {
                    a21[x][y]=a[i][j];
                    b21[x][y]=b[i][j];
                }
        for(int i=k,x=0;i<n,x<k;i++,x++)
            for(int j=k,y=0;j<n,y<k;j++,y++)
                {
                    a22[x][y]=a[i][j];
                    b22[x][y]=b[i][j];
                }
        */

        add(k,a11,a22);
        add(k,b11,b22);
        display_matrix(k,a11);
        display_matrix(k,b11);
        s_multiply(k,a11,b11,p1);
        display_matrix(k,p1);
        display_matrix(k,a11);

        add(k,a21,a22);
        s_multiply(k,a21,b11,p2);
        display_matrix(k,p2);

        sub(k,b12,b22);
        s_multiply(k,a11,b12,p3);
        display_matrix(k,p3);

        sub(k,b21,b11);
        s_multiply(k,a22,b21,p4);
        display_matrix(k,p4);

        add(k,a11,a12);
        s_multiply(k,a11,b22,p5);
        display_matrix(k,p5);

        sub(k,a21,a11);
        add(k,b11,b12);
        s_multiply(k,a21,b11,p6);
        display_matrix(k,p6);

        sub(k,a12,a22);
        add(k,b21,b22);
        s_multiply(k,a12,b21,p7);
        display_matrix(k,p7);

        add(k,p1,p4);
        add(k,p5,p7);
        sub(k,p1,p5);
        copy(k,c11,p1);
        add(k,p3,p5);
        copy(k,c12,p3);
        add(k,p2,p4);
        copy(k,c21,p2);
        add(k,p1,p3);
        add(k,p2,p6);
        sub(k,p1,p2);
        copy(k,c22,p1);
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                {
                    c[i][j]=c11[i][j];
                }
        for(int i=0,x=0;i<k,x<k;i++,x++)
            for(int j=k,y=0;j<n,y<k;j++,y++)
                {
                    c[i][j]=c12[x][y];
                }
        for(int i=k,x=0;i<n,x<k;i++,x++)
            for(int j=0,y=0;j<k,y<k;j++,y++)
            {
                    c[i][j]=c21[x][y];
            }
        for(int i=k,x=0;i<n,x<k;i++,x++)
            for(int j=k,y=0;j<n,y<k;j++,y++)
             {
                    c[i][j]=c22[x][y];
             }
    }
}
void main()
{
	int r1,r2,c1,c2;
	printf("Enter row and columns of matrix (of form (2^n)*(2^n))");
	printf("Enter row of matrix 1\n");
	scanf("%d",&r1);
	printf("Enter column of matrix 1\n");
	scanf("%d",&c1);
	printf("Enter row of matrix 2\n");
	scanf("%d",&r2);
	printf("Enter column of matrix 2\n");
	scanf("%d",&c2);
	int a[r1][c1],b[r2][c2];
	build_matrix(r1,a);
	build_matrix(r2,b);
	if(c1==r2)
	{
		int c[r1][c2];
		s_multiply(r1,a,b,c);
		printf("Matrix after multiplication\n");
		display_matrix(r1,c);
	}
	else
		printf("Multiplication not possible\n");
}

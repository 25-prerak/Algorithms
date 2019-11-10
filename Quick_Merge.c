#include<stdio.h>
#define INF 9999
int partition(int a[],int p,int r)
{
    int t1,t2,i;
    i=p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=a[r])
        {
            i=i+1;
            t1=a[i];
            a[i]=a[j];
            a[j]=t1;
        }
    }
    t2=a[i+1];
    a[i+1]=a[r];
    a[r]=t2;
    return (i+1);
}
void quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q;
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
void merge(int a[],int p,int q,int r)
{
    int n1,n2,i,j;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1],R[n2+1];
    for(i=0;i<n1;i++)
        L[i]=a[p+i];
    for(j=0;j<n2;j++)
        R[j]=a[q+1+j];
    L[n1+1]=INF;
    R[n2+1]=INF;
    i=j=0;
    for(int k=p;k<=r;k++)
    {
        if((L[i]<=R[j])&&(i<n1))
        {
            a[k]=L[i];
            i++;
        }
        else if(j<n2)
        {
            a[k]=R[j];
            j++;
        }
    }
}
void mergesort(int a[],int p,int r)
{
    int q=(p+r)/2;
    if(p<r)
    {
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void main()
{
    int a[]={4,2,9,7,1,6,3,8,5};
    quicksort(a,0,8);
    for(int i=0;i<9;i++)
        printf("%d\n",a[i]);
    mergesort(a,0,8);
    for(int i=0;i<9;i++)
        printf("%d\n",a[i]);
}

#include <stdio.h>
#include <stdlib.h>
void sort(int s[],int f[], int n)
{  int t1,t2;
   int i, j;
   for (i = 0; i < n-1; i++)
   {
      for (j = 0; j < n-i-1; j++)
        { if (f[j] > f[j+1])
            {
              t1 = f[j];
              t2 = s[j];
              f[j] = f[j+1];
              s[j] = s[j+1];
              f[j+1] = t1;
              s[j+1] = t2;
            }
        }
   }
}
void greedy_activity_selector(int s[],int f[],int a[],int n)
{
    // 1: It implies the activity is selected 0:activity is not selected
    a[0]=1;
    int i=0;
    for(int m=1;m<n;m++)
    {
        if(s[m]>=f[i])
        {
            a[m]=1;
            i=m;
        }
        else
            a[m]=0;
   }
}
int main()
{
    int n;
    printf("Enter the total no. of activities:\n");
    scanf("%d",&n);
    int st[n],ft[n],ac[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter start time of activity %d\n",i+1);
        scanf("%d",&st[i]);
        printf("Enter finish time of activity %d\n",i+1);
        scanf("%d",&ft[i]);
    }
    //Now Sorting both the arrays w.r.t increasing order of finish time
    sort(st,ft,n);
    greedy_activity_selector(st,ft,ac,n);
    printf("The activities selected are:\n");
    for(int i=0;i<n;i++)
    {
        if(ac[i]==1)
            printf("Activity No. : %d\n",i+1);
        else
            continue ;
    }
    return 0;
}

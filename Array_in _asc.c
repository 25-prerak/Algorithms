#include <stdio.h>
void bubbleSort(int a[], int n)
{  int temp = 0;
   int i, j;
   for (i = 0; i < n-1; i++)
   {
      for (j = 0; j < n-i-1; j++)
        { if (a[j] > a[j+1])
            {
              temp = a[j];
              a[j] = a[j+1];
              a[j+1] = temp;
            }
        }
   }
}

int main()
{
  int n,i;
  int a[100];
  printf("Enter number of numbers \n");
  scanf("%d",&n);
  printf("Enter numbers in the array :\n");
  for( i = 0 ; i < n ; i++)
  {
    scanf("%d",&a[i]);
  }
  bubbleSort(a,n);
  printf("Sorted list in ascending order is : \n");
  for( i = 0 ; i < n ; i++)
  {
    printf(" %d ",a[i]);
  }
}
